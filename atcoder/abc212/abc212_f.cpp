#include "bits/stdc++.h"

using i64 = long long;

constexpr int LOG = 20;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, q;
  std::cin >> n >> m >> q;
  int cnt = 0;
  std::vector<std::pair<int, int>> f;
  std::vector<std::vector<int>> t(n);
  std::vector<std::vector<int>> ts(n);
  std::vector<std::vector<int>> te(n);
  std::map<std::pair<int, int>, int> mp;
  std::vector nxt(2 * m, std::vector<int>(LOG + 1, -1));
  for (int i = 0; i < m; ++i) {
    int a, b, c, d;
    std::cin >> a >> c >> b >> d;
    --a, --c;
    ts[a].push_back(b);
    te[c].push_back(d);
    t[a].push_back(b);
    t[c].push_back(d);
    if (mp.count({a, b}) == false) {
      mp[{a, b}] = cnt++;
      f.push_back({a, b});
    }
    if (mp.count({c, d}) == false) {
      mp[{c, d}] = cnt++;
      f.push_back({c, d});
    }
    nxt[mp[{a, b}]][0] = mp[{c, d}];
  }
  for (int i = 0; i < n; ++i) {
    std::sort(t[i].begin(), t[i].end());
    std::sort(ts[i].begin(), ts[i].end());
    std::sort(te[i].begin(), te[i].end());
  }
  for (int i = 0; i < n; ++i) {
    for (int j : te[i]) {
      if (ts[i].size() && j <= ts[i].back()) {
        int l = std::lower_bound(ts[i].begin(), ts[i].end(), j) - ts[i].begin();
        if (ts[i][l] != j) {
          nxt[mp[{i, j}]][0] = mp[{i, ts[i][l]}];
        }
      }
    }
  }
  for (int j = 0; j < LOG; ++j) {
    for (int i = 0; i < cnt; ++i) {
      if (nxt[i][j] == -1) {
        continue;
      }
      nxt[i][j + 1] = nxt[nxt[i][j]][j];
    }
  }
  while (q--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    --y;
    if (ts[y].empty()) {
      std::cout << y + 1 << "\n";
      continue;
    }
    if (ts[y].back() < x) {
      std::cout << y + 1 << "\n";
      continue;
    }
    int l = std::lower_bound(ts[y].begin(), ts[y].end(), x) - ts[y].begin();
    int id = mp[{y, ts[y][l]}];
    int lo = 0, hi = (1 << 20);
    auto find = [&](int cur, int dep) {
      for (int i = LOG; i >= 0; --i) {
        if (dep >> i & 1) {
          if (cur == -1) {
            return cur;
          }
          cur = nxt[cur][i];
        }
      }
      return cur;
    };
    while (hi - lo > 1) {
      int mi = (lo + hi) / 2;
      int cur = find(id, mi);
      if (cur != -1 && f[cur].second < z) {
        lo = mi;
      } else {
        hi = mi;
      }
    }
    int e = find(id, lo);
    if (nxt[e][0] != -1) {
      if (f[e].second > ts[f[e].first].back()) {
        std::cout << f[e].first + 1 << "\n";
        continue;
      }
      int l2 = std::lower_bound(ts[f[e].first].begin(), ts[f[e].first].end(), f[e].second) - ts[f[e].first].begin();
      if (ts[f[e].first][l2] < z) {
        std::cout << f[e].first + 1 << " " << f[nxt[e][0]].first + 1 << "\n";
      } else {
        std::cout << f[e].first + 1 << "\n";
      }
    } else {
      std::cout << f[e].first + 1 << "\n";
    }
  }

  return 0;
}
