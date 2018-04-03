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

constexpr int MAXN = 66;
int n;
bool adj[MAXN][MAXN];
int deg[MAXN];
int inds[MAXN];
vector<pii> graph[MAXN];
map<pair<ll, int>, bool> memo;
bool dfs(ll used, int idx) {
    while (idx < n and used & (1LL << inds[idx])) {
        ++idx;
    }

    if (idx == n) {
        return true;
    }

    pair<ll, int> state(used, idx);
    if (memo.find(state) != end(memo))
        return memo[state];

    bool res = false;
    for (const pii& p : graph[inds[idx]]) {
        int j = p.first;
        int k = p.second;
        if (used & (1LL << j)) continue;
        if (used & (1LL << k)) continue;

        ll new_mask = used | (1LL << inds[idx]) | (1LL << j) | (1LL << k);
        if (dfs(new_mask, idx + 1)) {
            return memo[state] = true;
        }
    }

    return memo[state] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    while (cin >> m) {
        if (!m) break;

        vector<string> names;
        vector<pair<string, string>> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
            names.push_back(edges[i].first);
            names.push_back(edges[i].second);
        }
        sort(begin(names), end(names));
        names.erase(unique(begin(names), end(names)), end(names));
        n = names.size();

        if (n % 3 != 0) {
            cout << "impossible" << '\n';
            continue;
        }

        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < m; ++i) {
            int x = lower_bound(begin(names), end(names), edges[i].first) - begin(names);
            int y = lower_bound(begin(names), end(names), edges[i].second) - begin(names);
            adj[x][y] = 1;
            adj[y][x] = 1;
        }

        for (int i = 0; i < n; ++i) {
            graph[i].clear();
        }

        int total_triangles = 0;
        memset(deg, 0, sizeof(deg));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!adj[i][j]) continue;
                for (int k = j + 1; k < n; ++k) {
                    if (!adj[i][k] or !adj[j][k]) {
                        continue;
                    }

                    ++total_triangles;
                    ++deg[i];
                    ++deg[j];
                    ++deg[k];

                    graph[i].emplace_back(j, k);
                    graph[j].emplace_back(i, k);
                    graph[k].emplace_back(i, j);
                }
            }

            inds[i] = i;
        }

        if (3 * total_triangles < n) {
            cout << "impossible" << '\n';
            continue;
        }

        sort(inds, inds + n, [](const int& a, const int& b) {
            return deg[a] < deg[b];
        });

        memo.clear();
        bool res = dfs(0LL, 0);
        cout << (res ? "possible" : "impossible") << '\n';
    }

    return 0;
}
