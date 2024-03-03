#include "bits/stdc++.h"

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  double a, b;
  std::cin >> a >> b;
  std::cout << std::fixed << std::setprecision(6) << (a - b) / 3.0 + b << "\n";

  return 0;
}
