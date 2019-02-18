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

    int n;
    cin >> n;
    vector<vi> dist(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    vi req_masks(n, 0);
    int q;
    cin >> q;
    while (q-- > 0) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        req_masks[v] |= (1 << u);
    }

    constexpr int INF = 1e9 + 7;
    vector<vi> dp(1 << n, vi(n, INF));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (dp[mask][u] == INF) continue;
            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) continue;
                if ((mask & req_masks[v]) != req_masks[v]) continue;
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + dist[u][v]);
            }
        }
    }

    int ans = INF;
    int full = 1 << n;
    --full;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[full][i]);
    }

    cout << ans << '\n';
    
    return 0;
}
