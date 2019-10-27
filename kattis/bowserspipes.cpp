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

    vector<vi> graph(n);

    queue<int> q;
    vi sinks;
    vi fin(n, -1), hops(n, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == -1) {
            fin[i] = i;
            sinks.push_back(i);
            q.push(i);
        } else {
            graph[x].push_back(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            // cout << "edge " << u << ' ' << v << '\n';
            if (fin[v] == -1) {
                fin[v] = fin[u];
                hops[v] = hops[u] + 1;
                q.push(v);
            }
        }
    }

    sort(all(sinks));
    vi ans(sinks.size(), -1);
    for (int i = 0; i < n; ++i) {
        // cout << i << ' ' << fin[i] << '\n';
        if (fin[i] != i and graph[i].empty()) {
            auto idx = lower_bound(all(sinks), fin[i]) - begin(sinks);
            if (ans[idx] == -1 or hops[i] < hops[ans[idx]])
                ans[idx] = i;
        }
    }

    int qq;
    cin >> qq;
    while (qq-- > 0) {
        int u;
        cin >> u;
        int idx = lower_bound(all(sinks), fin[u]) - begin(sinks);
        cout << ans[idx] << '\n';
    }

    return 0;
}
