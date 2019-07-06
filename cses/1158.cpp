#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    cin >> n >> x;
    vi h(n);
    vi s(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    constexpr int INF = 1e9 + 7;
    vi dp(x + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = x - h[i]; j >= 0; --j) {
            dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
        }
    }

    cout << *max_element(all(dp)) << '\n';

    return 0;
}
