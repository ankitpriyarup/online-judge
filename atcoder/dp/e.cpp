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

    constexpr int MAXV = 1000;
    int n, w;
    cin >> n >> w;

    // what is the min weight to get value i
    constexpr ll INF = 1e17;
    vector<ll> dp(MAXV * n + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        ll wi, vi;
        cin >> wi >> vi;
        for (int j = (int)dp.size() - 1 - vi; j >= 0; --j) {
            dp[j + vi] = min(dp[j + vi], dp[j] + wi);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < dp.size(); ++i) {
        if (dp[i] <= w)
            ans = i;
    }

    cout << ans << '\n';

    return 0;
}
