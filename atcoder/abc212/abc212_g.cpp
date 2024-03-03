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

  i64 p;
  std::cin >> p;
  std::vector<i64> div;
  for (i64 i = 1; 1LL * i * i <= p - 1; ++i) {
    if ((p - 1) % i == 0) {
      div.push_back(i);
      if ((p - 1) / i != i) {
        div.push_back((p - 1) / i);
      }
    }
  }
  std::sort(div.begin(), div.end());
  int len = div.size();
  std::vector<Z> cnt(len, 0);
  for (int i = 0; i < len; ++i) {
    cnt[i] = Z(p - 1) / Z(div[i]);
  }
  for (int i = len - 1; i >= 0; --i) {
    for (int j = i + 1; j < len; ++j) {
      if (div[j] % div[i] != 0) {
        continue;
      }
      cnt[i] -= cnt[j];
    }
  }
  Z ans = 1;
  for (int i = 0; i < len; ++i) {
    ans += Z(p - 1) / Z(div[i]) * cnt[i];
  }
  std::cout << ans.val() << "\n";

  return 0;
}
