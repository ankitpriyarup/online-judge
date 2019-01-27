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

    int n, m, v;
    cin >> n >> m >> v;
    --v;

    vi ids(n);
    iota(all(ids), 0);
    swap(ids[0], ids[v]);

    vector<pii> edges;
    for (int i = 1; i < n; ++i) {
        edges.emplace_back(0, i);
    }

    for (int i = 2; edges.size() < m and i < n; ++i) {
        for (int j = i + 1; edges.size() < m and j < n; ++j) {
            edges.emplace_back(i, j);
        }
    }

    if (edges.size() != m) {
        cout << "-1\n";
        return 0;
    }

    for (auto& p : edges) {
        cout << (ids[p.first] + 1) << ' ' << (ids[p.second] + 1) << '\n';
    }
    
    return 0;
}
