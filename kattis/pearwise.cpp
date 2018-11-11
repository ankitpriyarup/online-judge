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

void dfs(vector<bool>& vis,
         vector<vector<int>>& adj,
         int u) {

    if (vis[u])
        return;

    vis[u] = true;
    int n = vis.size();
    for (int v = 0; v < n; ++v) {
        if (adj[u][v] > adj[v][u]) {
            dfs(vis, adj, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    int p;
    string s;
    while (m-- > 0) {
        cin >> p >> s;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                adj[s[i] - 'A'][s[j] - 'A'] += p;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        vector<bool> vis(n, false);
        dfs(vis, adj, i);
        bool hit_all = true;
        for (int j = 0; j < n; ++j)
            hit_all &= vis[j];
        if (hit_all) {
            cout << (char)(i + 'A') << ": can win\n";
        } else {
            cout << (char)(i + 'A') << ": can't win\n";
        }
    }
    
    return 0;
}
