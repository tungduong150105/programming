#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    constexpr int MOD = 1E9 + 7;
    int n, m; cin >> n >> m;
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        --x[i];
    }
    std::vector<int> dp(m, 0);
    if (x[0] != -1) {
        dp[x[0]] = 1;
    } else {
        for (int i = 0; i < m; ++i) {
            dp[i] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        std::vector<int> ndp(m, 0);
        if (x[i] != -1) {
            for (int j = -1; j <= 1; ++j) {
                if (x[i] + j >= 0 && x[i] + j < m) {
                    ndp[x[i]] += dp[x[i] + j];
                    ndp[x[i]] %= MOD;
                }
            }
        } else {
            for (int j = 0; j < m; ++j) {
                for (int k = -1; k <= 1; ++k) {
                    if (j + k >= 0 && j + k < m) {
                        ndp[j] += dp[j + k];
                        ndp[j] %= MOD;
                    }
                }
            }
        }
        std::swap(dp, ndp);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans << "\n";

    return 0;
}