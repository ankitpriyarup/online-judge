#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int INF = 1e9 + 7;

// Solve a single case and print it (no newline at the end).
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        --u; --v;
        adj[u][v] = adj[v][u] = w;
    }

    for (int k = 0; k < n; ++k) {
        adj[k][k] = 0;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    ll best_dist = INF;
    int ways = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        ll sum_dist = 0;
        for (u = 0; u < n; ++u) {
            int min_dist = INF;

            bool u_fruit = (mask & (1 << u)) == 0;
            for (v = 0; v < n; ++v) {
                if (u == v) continue;
                bool v_fruit = (mask & (1 << v)) == 0;
                if (u_fruit == v_fruit) continue;

                min_dist = min(min_dist, adj[u][v]);
            }

            if (min_dist == INF) {
                sum_dist = INF;
                break;
            }

            sum_dist += min_dist;
        }

        if (sum_dist == INF)
            continue;

        if (sum_dist < best_dist) {
            ways = 0;
            best_dist = sum_dist;
        }

        if (sum_dist == best_dist)
            ++ways;
    }

    cout << ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        cout << "Case #" << case_num << ": ";
        solve();
        cout << '\n';
    }
    
    return 0;
}
