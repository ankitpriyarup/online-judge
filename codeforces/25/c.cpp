#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 303;
int d[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int m;
    cin >> m;
    while (m-- > 0) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        d[u][v] = min(d[u][v], w);
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][u] + w + d[v][j]);
                d[i][j] = min(d[i][j], d[i][v] + w + d[u][j]);

                if (i < j)
                    ans += d[i][j];
            }
        }

        cout << ans << ' ';
    }

    return 0;
}
