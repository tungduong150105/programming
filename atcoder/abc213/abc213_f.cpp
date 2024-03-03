#include "bits/stdc++.h"

using i64 = long long;

struct SuffixArray {
  int n;
  std::vector<int> sa, rk, tmp, lcp;
  SuffixArray(const std::string &s) : n(int(s.size())) {
    sa.resize(n + 1);
    rk.resize(n + 1);
    lcp.resize(n + 1);
    tmp.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
      sa[i] = i;
      rk[i] = i < n ? s[i] : -1;
    }
    for (int k = 1; k <= n; k *= 2) {
      auto Cmp = [&](const int &lhs, const int &rhs) {
        if (rk[lhs] != rk[rhs]) {
          return rk[lhs] < rk[rhs];
        }
        int nlhs = lhs + k <= n ? rk[lhs + k] : -1;
        int nrhs = rhs + k <= n ? rk[rhs + k] : -1;
        return nlhs < nrhs;
      };
      std::sort(sa.begin(), sa.end(), Cmp);
      tmp = rk;
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; ++i) {
        tmp[sa[i]] = tmp[sa[i - 1]] + Cmp(sa[i - 1], sa[i]);
      }
      rk = tmp;
    }
    for (int i = 0; i <= n; ++i) {
      rk[sa[i]] = i;
    }
    for (int i = 0, k = 0; i < n; ++i, k ? k-- : 0) {
      if (rk[i] == n) {
        k = 0;
        continue;
      }
      int j = sa[rk[i] + 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
        ++k;
      }
      lcp[rk[i]] = k;
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  SuffixArray sa(s);
  std::vector<i64> tot(n + 1, 0);
  {
    std::vector<i64> ans(n + 1, 0);
    std::set<int> unq;
    std::vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      int len = n - sa.sa[i + 1];
      int v = sa.lcp[i];
      tot[sa.sa[i + 1]] -= len;
      ans[sa.sa[i + 1]] += ans[sa.sa[i]];
      ans[sa.sa[i + 1]] += len;
      while (unq.size()) {
        auto it = *(--unq.end());
        if (it > v) {
          ans[sa.sa[i + 1]] -= 1LL * cnt[it] * it;
          cnt[v] += cnt[it];
          ans[sa.sa[i + 1]] += 1LL * cnt[it] * v;
          cnt[it] = 0;
          unq.erase(it);
          unq.insert(v);
        } else {
          break;
        }
      }
      ++cnt[len];
      unq.insert(len);
    }
    for (int i = 0; i < n; ++i) {
      tot[i] += ans[i];
    }
  }
  {
    std::vector<i64> ans(n + 1, 0);
    std::set<int> unq;
    std::vector<int> cnt(n + 1, 0);
    for (int i = n; i > 0; --i) {
      int len = n - sa.sa[i];
      int v = sa.lcp[i];
      if (i != n) {
        ans[sa.sa[i]] += ans[sa.sa[i + 1]];
      }
      ans[sa.sa[i]] += len;
      while (unq.size()) {
        auto it = *(--unq.end());
        if (it > v) {
          ans[sa.sa[i]] -= 1LL * cnt[it] * it;
          cnt[v] += cnt[it];
          ans[sa.sa[i]] += 1LL * cnt[it] * v;
          cnt[it] = 0;
          unq.erase(it);
          unq.insert(v);
        } else {
          break;
        }
      }
      ++cnt[len];
      unq.insert(len);
    }
    for (int i = 0; i < n; ++i) {
      tot[i] += ans[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    std::cout << tot[i] << "\n";
  }

  return 0;
}
