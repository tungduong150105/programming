#include "bits/stdc++.h"

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<std::string> base = {"H", "2B", "3B", "HR"};
  std::vector<std::string> s(4);
  for (int i = 0; i < 4; ++i) {
    std::cin >> s[i];
  }
  std::sort(base.begin(), base.end());
  std::sort(s.begin(), s.end());
  if (s == base) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }

  return 0;
}
