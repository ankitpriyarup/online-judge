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

    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    constexpr ll INF = 1e18;
    vector<ll> dp(n, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= i + k and j < n; ++j) {
            dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n - 1] << '\n';
    
    return 0;
}
