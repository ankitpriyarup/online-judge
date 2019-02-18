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

    int n, m;
    cin >> n >> m;

    vector<vi> bad(n, vi(n, 0));

    for (int i = 0; i < n; ++i) {
        bad[i][i] = true;
    }

    vi slope(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> slope[i] >> p[i];
    }
    while (m-- > 0) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        bad[u][v] = bad[v][u] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, p[i]);
        for (int j = 0; j < n; ++j) {
            if (bad[i][j]) continue;
            int v = slope[j] * p[i] + p[j];
            ans = max(ans, v);
            for (int k = 0; k < n; ++k) {
                if (bad[i][k] or bad[j][k]) continue;
                ans = max(ans, slope[k] * v + p[k]);
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}
