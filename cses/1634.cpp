#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, x; cin >> n >> x;
    std::vector<int> dp(x + 1, x + 1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        for (int j = c; j <= x; ++j) {
            dp[j] = std::min(dp[j], dp[j - c] + 1);
        }
    }
    if (dp[x] == x + 1) {
        dp[x] = -1;
    }
    cout << dp[x] << "\n";

    return 0;
}