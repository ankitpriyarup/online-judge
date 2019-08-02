#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool valid(const vector<pii>& edges, int n, int flip_idx) {
    vector<vector<bool>> adj(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        adj[i][i] = true;
    }

    for (int i = 0; i < edges.size(); ++i) {
        int u, v;
        tie(u, v) = edges[i];

        if (i == flip_idx) 
            swap(u, v);

        adj[u][v] = true;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
            }
        }
    }

    bool res = true;
    for (int i = 0; i < n; ++i) {
        res &= adj[i][0] && adj[0][i];
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    int n, m;
    while (cin >> n >> m) {
        vector<pii> edges;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            edges.emplace_back(u, v);
        }
        
        cout << "Case " << tc++ << ": ";
        if (valid(edges, n, -1)) {
            cout << "valid\n";
        } else {
            bool found = false;
            for (int i = 0; i < m; ++i) {
                if (valid(edges, n, i)) {
                    cout << edges[i].first << ' ' << edges[i].second << '\n';
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "invalid\n";
            }
        }
    }
    
    return 0;
}
