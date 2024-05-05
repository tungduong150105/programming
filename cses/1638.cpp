#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    constexpr int MOD = 1E9 + 7;
    int n; cin >> n;
    std::vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    std::vector dp(n, std::vector<int> (n, 0));
    dp[0][0] = (s[0][0] == '.');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '*') {
                continue;
            }
            if (i) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            if (j) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}