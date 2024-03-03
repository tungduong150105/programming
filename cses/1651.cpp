#include <bits/stdc++.h>
 
using i64 = long long;
 
template <typename T>
struct FenwickTree {
  int n;
  std::vector<T> a;
  FenwickTree(int m = 0) {
    init(m);
  }
  void init(int m) {
    n = m;
    a.resize(m, T());
  }
  void add(int p, T v) {
    for (int i = p + 1; i <= n; i += i & -i) {
      a[i - 1] += v;
    }
  }
  T sum(int p) {
    T ans = T();
    for (int i = p; i > 0; i -= i & -i) {
      ans += a[i - 1];
    }
    return ans;
  }
  T rangeSum(int l, int r) {
    return sum(r) - sum(l);
  }
};
 
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
 
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  FenwickTree<i64> fen(n);
  while (q--) {
    int cmd;
    std::cin >> cmd;
    if (cmd == 1) {
      int l, r, u;
      std::cin >> l >> r >> u;
      --l, --r;
      fen.add(l, u);
      fen.add(r + 1, -u);
    } else {
      int k;
      std::cin >> k;
      --k;
      std::cout << 1LL * a[k] + fen.sum(k + 1) << "\n";
    }
  }
 
  return 0;
}
