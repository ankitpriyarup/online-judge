#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1000006;
string edges[MAXN >> 1][2];
string vertices[MAXN];

vi graph[MAXN];
int in_deg[MAXN];
int eaten[MAXN];
int level[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> edges[i][0] >> edges[i][1];

            vertices[2 * i] = edges[i][0];
            vertices[2 * i + 1] = edges[i][1];

            graph[i].clear();
        }

        sort(vertices, vertices + n + n);
        int m = unique(vertices, vertices + n + n) - vertices;

        memset(in_deg, 0, sizeof(in_deg));
        memset(eaten, 0, sizeof(eaten));
        for (int i = 0; i < n; ++i) {
            int u = lower_bound(vertices, vertices + m, edges[i][0]) - vertices;
            int v = lower_bound(vertices, vertices + m, edges[i][1]) - vertices;

            // cout << vertices[u] << ' ' << vertices[v] << ' ' << u << ' ' << v << '\n';

            graph[u].push_back(v);
            ++in_deg[v];
        }

        queue<int> q;
        memset(level, 0, sizeof(level));
        for (int i = 0; i < m; ++i) {
            // cout << i << ' ' << vertices[i] << ' ' << in_deg[i] << '\n';
            if (in_deg[i] == 0) {
                q.push(i);
                level[i] = 1;
            }
        }

        vector<tuple<int, int, int>> res;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            res.push_back(make_tuple(level[u], in_deg[u], u));

            for (int v : graph[u]) {
                level[v] = max(level[v], level[u] + 1);
                if (++eaten[v] == in_deg[v]) {
                    q.push(v);
                }
            }
        }

        sort(begin(res), end(res));
        for (auto& t : res) {
            int a, b, c;
            tie(a, b, c) = t;
            cout << a << '.' << b << ' ' << vertices[c] << '\n';
        }
    }
    
    return 0;
}
