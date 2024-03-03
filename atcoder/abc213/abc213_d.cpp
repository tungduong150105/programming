#include "bits/stdc++.h"

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> e(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    std::sort(e[i].begin(), e[i].end());
  }
  std::vector<int> ans;
  std::function<void(int, int)> dfs = [&](int u, int p) {
    ans.push_back(u);
    for (int v : e[u]) {
      if (v == p) {
        continue;
      }
      dfs(v, u);
      ans.push_back(u);
    }
  };
  dfs(0, -1);
  int len = int(ans.size());
  for (int i = 0; i < len; ++i) {
    std::cout << ans[i] + 1 << " \n"[i == len - 1];
  }

  return 0;
}
