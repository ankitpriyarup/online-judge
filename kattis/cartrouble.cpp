#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1005;
vi graph[MAXN], rev[MAXN];
bool vis1[MAXN];
bool vis2[MAXN];

int ids[MAXN];

void dfs1(int u) {
    if (vis1[u]) return;
    vis1[u] = true;
    for (int v : graph[u])
        dfs1(v);
}

void dfs2(int u) {
    if (vis2[u]) return;
    vis2[u] = true;
    for (int v : rev[u])
        dfs2(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int deg;
        cin >> ids[i] >> deg;
        while (deg-- > 0) {
            int v;
            cin >> v;
            graph[ids[i]].push_back(v);
            rev[v].push_back(ids[i]);
        }
    }

    dfs1(0);
    dfs2(0);

    bool printed = false;
    for (int i = 0; i < n; ++i) {
        if (!vis2[ids[i]]) {
            printed = true;
            cout << "TRAPPED " << ids[i] << '\n';
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis1[ids[i]]) {
            printed = true;
            cout << "UNREACHABLE " << ids[i] << '\n';
        }
    }

    if (!printed) {
        cout << "NO PROBLEMS\n";
    }

    return 0;
}
