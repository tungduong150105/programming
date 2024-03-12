#include <bits/stdc++.h>
#include <limits>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  i64 h, w, c;
  std::cin >> h >> w >> c;

  std::vector a(h, std::vector<i64> (w, 0));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cin >> a[i][j];
    }
  }

  auto solve = [&]() {
    constexpr i64 inf = -1E18;
    std::vector f(h, std::vector<i64> (w, inf));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        f[i][j] = 1LL * c * (i + j) - a[i][j];
        if (i != 0) {
          f[i][j] = std::max(f[i][j], f[i - 1][j]);
        }
        if (j != 0) {
          f[i][j] = std::max(f[i][j], f[i][j - 1]);
        }
      }
    }

    i64 ans = -inf;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (i == 0 && j == 0) {
          continue;
        }
        i64 mx = inf;
        if (i != 0) {
          mx = std::max(mx, f[i - 1][j]);
        }
        if (j != 0) {
          mx = std::max(mx, f[i][j - 1]);
        }
        ans = std::min(ans, 1LL * c * (i + j) + a[i][j] - mx);
      }
    }

    return ans;
  };

  i64 ans = solve();
  std::reverse(a.begin(), a.end());
  ans = std::min(ans, solve());
  std::reverse(a.begin(), a.end());
  for (auto &v : a) {
    std::reverse(v.begin(), v.end());
  }
  ans = std::min(ans, solve());

  std::cout << ans << "\n";

  return 0;
}
