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
#include <functional>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using state = pair<int, vector<vector<int>>>;

ll take_one(const vector<ll>& p) {
    int n = p.size();
    return n == 1 ? p[0] : p[n - 1] - p[n - 2];
}

vector<int> compress(int x, const vector<vector<int>>& adj) {
    vector<int> res = {x};
    for (int i = 0; i < 4; ++i) {
        res.insert(end(res), begin(adj[i]), end(adj[i]));
    }

    return res;
}

map<vector<int>, ll> memo;

ll dfs(const vector<vector<vector<ll>>>& psum, int x, vector<vector<int>>& adj, int dep=0) {
    vector<int> state = compress(x, adj);
    auto it = memo.find(state);
    if (it != end(memo)) {
        return it->second;
    }
    /*
    cout << "dfs(" << (x + 1) << ", " << dep << ")\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << adj[i][j];
        }
        cout << '\n';
    }
    */

    ll ans = 0LL;
    for (int y = 0; y < 4; ++y) {
        int u = x;
        int v = y;
        if (u > v)
            swap(u, v);

        if (adj[u][v] == 0) {
            continue;
        } else if (adj[u][v] == 1) {
            ll cur = take_one(psum[u][v]);
            // cout << "Taking single edge connecting " << x << ", " << y << " weight " << cur << '\n';
            adj[u][v] = 0;
            cur += dfs(psum, y, adj, dep+1);
            adj[u][v] = 1;
            ans = max(ans, cur);
        } else {
            int old = adj[u][v];

            ll cur = psum[u][v].back();
            // cout << "Taking all edges connecting " << x << ", " << y << " weight " << cur << '\n';
            adj[u][v] = 0;
            cur += dfs(psum, psum[u][v].size() % 2 ? y : x, adj, dep+1);
            ans = max(ans, cur);

            if (psum[u][v].size() >= 2) {
                cur = psum[u][v][psum[u][v].size() - 2];
                // cout << "Taking all but one edge connecting " << x << ", " << y << " weight " << cur << '\n';
                adj[u][v] = 1;
                cur += dfs(psum, psum[u][v].size() % 2 ? x : y, adj, dep+1);
                ans = max(ans, cur);
            }

            adj[u][v] = old;
        }
    }

    return memo[state] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int a, b;
    ll v;
    vector<vector<vector<ll>>> by_kind(4, vector<vector<ll>>(4));
    vector<vector<vector<ll>>> psum(4, vector<vector<ll>>(4));

    ll ans = 0LL;

    for (int i = 0; i < n; ++i) {
        cin >> a >> v >> b;
        if (a > b) {
            swap(a, b);
        }

        --a; --b;
        by_kind[a][b].push_back(v);
        ans = max(ans, v);
    }

    // make edge of cost v from node a to node b.
    // What's a valid path?
    // some starting node
    // only take each edge once
    //
    // start at starting node. Take all self loops. Take EVEN number to each
    // other node, but leave at least one edge (or dont). Move to next node.
    // Rinse + repeat.
    //
    // To do this, run a dfs. State: node, adj matrix. Matrix is either: allleft, 2 left, 1 left, no left

    for (int a = 0; a < 4; ++a) {
        for (int b = 0; b < 4; ++b) {
            if (by_kind[a][b].empty()) continue;
            sort(begin(by_kind[a][b]), end(by_kind[a][b]));
            reverse(begin(by_kind[a][b]), end(by_kind[a][b]));
            psum[a][b].resize(by_kind[a][b].size());
            partial_sum(begin(by_kind[a][b]), end(by_kind[a][b]), begin(psum[a][b]));
        }
    }

    vector<vector<int>> adj(4, vector<int>(4, 0));
    for (int a = 0; a < 4; ++a) {
        for (int b = 0; b < 4; ++b) {
            adj[a][b] = min(2, (int)by_kind[a][b].size());
        }
    }

    for (int i = 0; i < 4; ++i) {
        ll x = dfs(psum, i, adj);
        // cout << "Best start from " << (i + 1) << " is " << x << '\n';
        ans = max(ans, x);
    }

    cout << ans << '\n';

    return 0;
}
