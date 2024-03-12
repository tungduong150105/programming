#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::pair<int, int>> a(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> a[i].first >> a[i].second;
  }

  std::sort(a.begin(), a.end(), [&](const auto &lhs, const auto &rhs) {
    return lhs.second < rhs.second;
  });

  i64 ans = 0;
  int gcd = n;
  for (int i = 0; i < m; ++i) {
    int n_gcd = std::__gcd(gcd, a[i].first);
    ans += 1LL * (gcd - n_gcd) * a[i].second;
    gcd = n_gcd;
  }
  
  if (gcd != 1) {
    ans = -1;
  }

  std::cout << ans << "\n";

  return 0;
}
