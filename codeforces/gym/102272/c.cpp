#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 128;
int dist[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;

    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < MAXN; ++i) {
        dist[i][i] = 0;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        char u, v; int w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 0; k < MAXN; ++k) {
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (dist[s[i]][t[i]] > MAXN * 1003) {
            cout << -1 << '\n';
            return 0;
        }

        ans += dist[s[i]][t[i]];
    }

    cout << ans << '\n';

    return 0;
}
