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

template <typename G>
vector<int> dists(const G& graph, int u) {
    queue<int> q;
    vector<int> d(graph.size(), -1);
    q.push(u);

    d[u] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int v : graph[x]) {
            if (d[v] == -1) {
                d[v] = d[x] + 1;
                q.push(v);
            }
        }
    }

    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    --a;
    --b;
    vector<vector<int>> graph(n);
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> d0 = dists(graph, 0);
    vector<int> d1 = dists(graph, a);
    if (d0[a] == -1 or d1[b] == -1) {
        cout << -1;
        return 0;
    }

    cout << (d0[a] + d1[b]) << '\n';
    return 0;
}
