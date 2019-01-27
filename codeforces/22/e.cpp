#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int dfs(const vi& g, vi& vis, int u) {
    if (vis[u])
        return u;

    vis[u] = true;
    return dfs(g, vis, g[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi g(n);
    vi in_deg(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        --g[i];
        ++in_deg[g[i]];
    }

    vi vis(n, 0);
    // make graph into SCC
    // input graph is special: n edges, and every node has out-deg 1
    // this means that only option is (optional) lines into cycles
    // find all of them and merge them
    vector<pii> segs;
    int lines = 0;
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0) {
            ++lines;
            int j = dfs(g, vis, i);
            segs.emplace_back(i, j);
        }
    }

    // then there are straight cycles
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(g, vis, i);
            segs.emplace_back(i, i);
        }
    }

    int m = segs.size();
    if (m == 1 and lines == 0) {
        cout << 0 << '\n';
        return 0;
    }

    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
        int j = (i + 1) % m;
        cout << (segs[i].second + 1) << ' ' << (segs[j].first + 1) << '\n';
    }

    return 0;
}
