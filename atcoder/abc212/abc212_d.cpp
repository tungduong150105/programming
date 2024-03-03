#include "bits/stdc++.h"

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::priority_queue<i64, std::vector<i64>, std::greater<>> pq;
  i64 sum = 0;
  int n;
  std::cin >> n;
  while (n--) {
    int cmd;
    std::cin >> cmd;
    if (cmd == 1) {
      int x;
      std::cin >> x;
      pq.push(x - sum);
    } else if (cmd == 2) {
      int x;
      std::cin >> x;
      sum += x;
    } else {
      std::cout << sum + pq.top() << "\n";
      pq.pop();
    }
  }

  return 0;
}
