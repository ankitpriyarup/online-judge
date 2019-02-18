#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    // reverse graph
    // greedily take smallest
    vi e(n);
    vi in_deg(n, 0);
    vector<vi> graph(n);
    set<pii> s;
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
        int d;
        cin >> d;
        for (int j = 0; j < d; ++j) {
            int u;
            cin >> u;
            --u;
            graph[i].push_back(u);
            ++in_deg[u];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0) {
            s.emplace(e[i], i);
        }
    }

    int offset = n - 1;
    int ans = 0;
    while (!s.empty()) {
        int u = begin(s)->second;
        s.erase(begin(s));
        for (int v : graph[u]) {
            if (--in_deg[v] == 0) {
                s.emplace(e[v], v);
            }
        }

        ans = max(ans, offset + e[u]);
        --offset;
    }

    cout << ans << '\n';
    
    return 0;
}
