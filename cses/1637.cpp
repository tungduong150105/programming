#include <bits/stdc++.h>

namespace std {
template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
template<class T>
explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    std::vector<int> dp(n + 1, -1);
    cout << std::y_combinator([&](auto self, int v) -> int {
        if (!v) {
            return 0;
        }
        if (dp[v] != -1) {
            return dp[v];
        }
        std::set<int> sub;
        int u = v;
        while (u) {
            sub.insert(u % 10);
            u /= 10;
        }
        int ans = 1E9;
        for (int x : sub) {
            if (x) {
                ans = std::min(ans, self(v - x) + 1);
            }
        }
        return dp[v] = ans;
    })(n) << "\n";

    return 0;
}