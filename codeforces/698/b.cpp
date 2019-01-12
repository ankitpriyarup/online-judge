#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200005;
int vis[MAXN];
vi cc;

int dfs(const vi& a, int u) {
    if (vis[u]) {
        return u;
    }

    vis[u] = 1;
    cc.push_back(u);
    return dfs(a, a[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        b[i] = a[i];
    }

    vi cycles;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            cc.clear();
            int u = dfs(a, i);
            if (vis[u] == 1) {
                cycles.push_back(u);
                // cout << "found cycle which includes " << (u + 1) << '\n';
            }
            for (int v : cc)
                vis[v] = 2;
        }
    }

    int root = -1;
    for (int i = 0; i < cycles.size(); ++i) {
        int u = cycles[i];
        if (a[u] == u) {
            root = i;
            break;
        }
    }
    if (root == -1) {
        a[cycles[0]] = cycles[0];
        root = 0;
    }

    for (int i = 0; i < cycles.size(); ++i) {
        if (i == root)
            continue;
        a[cycles[i]] = cycles[root];
    }

    int moves = 0;
    for (int i = 0; i < n; ++i) 
        moves += a[i] != b[i];
    cout << moves << '\n';
    for (int i = 0; i < n; ++i) {
        cout << (a[i] + 1) << ' ';
    }
    
    return 0;
}
