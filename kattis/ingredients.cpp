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

constexpr int MAXN = 1000006;
int n;
int budget;

vector<string> all_names;

struct edge {
    string src, dest;
    int price, prestige;

    edge(string src, string dest, int price, int prestige):
        src(src), dest(dest), price(price), prestige(prestige) {}
};

vector<edge> edges;

inline int lookup(const string& s) {
    return lower_bound(begin(all_names), end(all_names), s) - begin(all_names);
}

using tup = tuple<int, int, int>;
vector<vector<tup> > graph;
vector<ll> costs;
vector<ll> prestiges;
vector<bool> vis;

void dfs(int x) {
    if (vis[x])
        return;
    vis[x] = true;

    if (graph[x].empty()) {
        costs[x] = 0;
        prestiges[x] = 0;
        return;
    }

    costs[x] = 1e18;
    prestiges[x] = -1;
    int u, c, p;
    for (auto& e : graph[x]) {
        tie(u, c, p) = e;
        dfs(u);

        ll new_cost = costs[u] + c;
        ll new_prest = prestiges[u] + p;
        if (new_cost < costs[x] or (new_cost == costs[x] and new_prest > prestiges[x])) {
            costs[x] = new_cost;
            prestiges[x] = new_prest;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> budget;
    cin >> n;

    string src, dest, junk;
    int price, prestige;
    for (int i = 0; i < n; ++i) {
        cin >> dest >> src >> junk >> price >> prestige;
        edges.emplace_back(src, dest, price, prestige);

        all_names.push_back(src);
        all_names.push_back(dest);
    }

    sort(begin(all_names), end(all_names));
    all_names.resize(unique(begin(all_names), end(all_names)) - begin(all_names));

    graph.assign(all_names.size(), vector<tup>());
    costs.assign(all_names.size(), 0LL);
    prestiges.assign(all_names.size(), 0LL);
    vis.assign(all_names.size(), false);

    for (int i = 0; i < n; ++i) {
        int u = lookup(edges[i].src);
        int v = lookup(edges[i].dest);

        graph[v].push_back({u, edges[i].price, edges[i].prestige});
    }

    constexpr int MAX_COST = 10004;
    vector<vector<ll> > vals(2, vector<ll>(budget + 1, 0));
    int row = 0;
    for (int i = 0; i < all_names.size(); ++i) {
        dfs(i);

        for (int cost = 0; cost <= budget; ++cost) {
            vals[row][cost] = vals[1 - row][cost];
            if (costs[i] <= cost) {
                vals[row][cost] = max(vals[row][cost], prestiges[i] + vals[1 - row][cost - costs[i]]);
            }
        }

        row = 1 - row;
    }

    ll best_cost = 0LL;
    ll best_prest = 0LL;
    for (int cost = 0; cost <= budget; ++cost) {
        if (vals[1 - row][cost] > best_prest) {
            best_cost = cost;
            best_prest = vals[1 - row][cost];
        }
    }

    cout << best_prest << '\n' << best_cost << '\n';

    return 0;
}
