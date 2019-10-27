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

    int n, m;
    cin >> n >> m;

    vector<vi> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;

    vi previous(n, -1);
    q.push(0);
    previous[0] = -2;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (previous[v] == -1) {
                previous[v] = u;
                q.push(v);
            }
        }
    }

    if (previous[n - 1] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vi stk;
    int u = n - 1;
    while (u > 0) {
        stk.push_back(u);
        u = previous[u];
    }

    cout << stk.size() + 1 << '\n';
    cout << "1";
    while (!stk.empty()) {
        cout << ' ' << stk.back() + 1;
        stk.pop_back();
    }
    
    return 0;
}
