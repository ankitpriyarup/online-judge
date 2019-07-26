#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

vector<vi> read_tree() {
    int n;
    cin >> n;
    vector<vi> tree(n);
    for (int i = 1; i < n; ++i) { 
        int u, v;
        cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    return tree;
}

int find_diam(const vector<vi>& tree) {
    int n = tree.size();
    queue<int> q;
    vector<int> dist(n, n + 1);
    dist[0] = 0;
    q.push(0);
    int far = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        far = u;
        for (int v : tree[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    dist.assign(n, n + 1);
    dist[far] = 0;
    q.push(far);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : tree[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return *max_element(all(dist));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<vi> a = read_tree();
    vector<vi> b = read_tree();

    int diam = find_diam(a);
    int min_h = (find_diam(b) + 1) / 2;

    cout << (diam > min_h ? "GGEZ" : "FF") << '\n';
    
    return 0;
}
