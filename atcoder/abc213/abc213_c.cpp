#include "bits/stdc++.h"

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w, n;
  std::cin >> h >> w >> n;
  std::vector<int> A(n), B(n);
  std::vector<std::pair<int, int>> f;
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i] >> B[i];
    f.push_back({A[i], B[i]});
  }
  std::sort(A.begin(), A.end());
  A.erase(std::unique(A.begin(), A.end()), A.end());
  std::sort(B.begin(), B.end());
  B.erase(std::unique(B.begin(), B.end()), B.end());
  for (auto [u, v] : f) {
    std::cout << (std::lower_bound(A.begin(), A.end(), u) - A.begin()) + 1 << " " << (std::lower_bound(B.begin(), B.end(), v) - B.begin()) + 1 << "\n";
  }

  return 0;
}
