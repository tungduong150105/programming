#include "bits/stdc++.h"

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> s(h);
  for (int i = 0; i < h; ++i) {
    std::cin >> s[i];
  }
  constexpr int inf = 1E9;
  std::vector f(h, std::vector<int> (w, inf));
  std::deque<std::array<int, 3>> dq;
  dq.push_back({0, 0, 0});
  while (dq.size()) {
    auto [x, y, d] = dq.front();
    dq.pop_front();
    if (f[x][y] != inf) {
      continue;
    }
    f[x][y] = d;
    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (std::abs(i + j) != 1) {
          continue;
        }
        int _x = x + i;
        int _y = y + j;
        if (_x < 0 || _y < 0 || _x >= h || _y >= w || s[_x][_y] == '#') {
          continue;
        }
        dq.push_front({_x, _y, d});
      }
    }
    for (int i = -2; i <= 2; ++i) {
      for (int j = -2;j <= 2; ++j) {
        if (std::abs(i) + std::abs(j) == 4) {
          continue;
        }
        int _x = x + i;
        int _y = y + j;
        if (_x < 0 || _y < 0 || _x >= h || _y >= w) {
          continue;
        }
        dq.push_back({_x, _y, d + 1});
      }
    }
  }
  std::cout << f[h - 1][w - 1] << "\n";

  return 0;
}
