#include "bits/stdc++.h"

using i64 = long long;

constexpr int P = 998244353;
int norm(int x) {
  if (x >= P) {
    x -= P;
  }
  if (x < 0) {
    x += P;
  }
  return x;
}
template <typename T> T power(T a, int n) {
  T res = 1;
  for (; n; n /= 2, a *= a) {
    if (n & 1) {
      res *= a;
    }
  }
  return res;
}
struct Z {
  int x;
  Z(int _x = 0) : x(norm(_x)) {}
  Z(i64 _x) : x(norm(_x % P)) {}
  int val() const { return x; }
  Z operator-() const { return Z(norm(P - x)); }
  Z inv() const { return power(*this, P - 2); }
  Z &operator+=(const Z &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  Z &operator-=(const Z &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  Z &operator*=(const Z &rhs) {
    x = x * 1ll * rhs.x % P;
    return *this;
  }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  friend Z operator+(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res += rhs;
    return res;
  }
  friend Z operator-(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res -= rhs;
    return res;
  }
  friend Z operator*(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res *= rhs;
    return res;
  }
  friend Z operator/(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res /= rhs;
    return res;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::pair<int, int>> ban;
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    ban.emplace_back(u, v);
  }
  std::vector<Z> dp(n, 0);
  dp[0] = 1;
  for (int i = 1; i <= k; ++i) {
    std::vector<Z> ndp(n, 0);
    Z s = std::accumulate(dp.begin(), dp.end(), Z(0));
    for (int j = 0; j < n; ++j) {
      ndp[j] = s - dp[j];
    }
    for (auto [u, v] : ban) {
      ndp[u] -= dp[v];
      ndp[v] -= dp[u];
    }
    std::swap(dp, ndp);
  }
  std::cout << dp[0].val() << "\n";

  return 0;
}
