#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int find(vi& uf, int x) {
    return uf[x] = uf[x] == x ? x : find(uf, uf[x]);
}

int merge(vi& uf, vi& b, vi& w, int x, int y) {
    int xr = find(uf, x);
    int yr = find(uf, y);
    if (xr == yr)
        return 0;
    uf[xr] = yr;
    b[yr] += b[xr];
    w[yr] += w[xr];
    b[xr] = 0;
    w[xr] = 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<int> uf(n * m), b(n * m), w(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            uf[m * i + j] = m * i + j;
            b[m * i + j] = grid[i][j] == '#';
            w[m * i + j] = grid[i][j] == '.';
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0 and grid[i - 1][j] != grid[i][j]) {
                merge(uf, b, w, m * (i - 1) + j, m * i + j);
            }
            if (j > 0 and grid[i][j - 1] != grid[i][j]) {
                merge(uf, b, w, m * i + j - 1, m * i + j);
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (uf[m * i + j] != m * i + j)
                continue;

            int black = b[m * i + j];
            int white = w[m * i + j];
            ans += 1LL * black * white;
        }
    }

    cout << ans << '\n';
    return 0;
}
