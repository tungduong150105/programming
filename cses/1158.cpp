#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, x; cin >> n >> x;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    std::vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= h[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    cout << dp[x] << "\n";

    return 0;
}
