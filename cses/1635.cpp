#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    constexpr int MOD = 1E9 + 7;
    int n, x; cin >> n >> x;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    std::vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + c[j] <= x) {
                dp[i + c[j]] += dp[i];
                dp[i + c[j]] %= MOD;
            }
        }
    }
    cout << dp[x] << "\n";

    return 0;
}