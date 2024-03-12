#include "bits/stdc++.h"

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<std::string> s(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
  }
  std::vector<std::vector<int>> e(n * n);
  auto f = [&](int x, int y) {
    return x * n + y;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '#') {
        continue;
      }
      if (i + 1 < n && s[i + 1][j] != '#') {
        e[f(i, j)].push_back(f(i + 1, j));
        e[f(i + 1, j)].push_back(f(i, j));
      }
      if (j + 1 < n && s[i][j + 1] != '#') {
        e[f(i, j)].push_back(f(i, j + 1));
        e[f(i, j + 1)].push_back(f(i, j));
      }
    }
  }
  i64 ans = 0;
  std::vector<bool> used(n * n, false);
  std::function<void(int, int)> dfs = [&](int u, int dep) {
    used[u] = true;
    if (dep == 0) {
      ++ans;
      return;
    }
    for (int v : e[u]) {
      if (used[v]) {
        continue;
      }
      dfs(v, dep - 1);
    }
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '#') {
        continue;
      }
      for (int l = 0; l < n * n; ++l) {
        used[l] = false;
      }
      dfs(f(i, j), k - 1);
      std::cout << ans << "\n";
    }
  }
  std::cout << ans << "\n";

  return 0;
}