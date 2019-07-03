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
    while (cin >> n) {
        vi degree(n, 1);
        vi a(n - 2);
        for (auto& x : a) {
            cin >> x;
            --x;
            ++degree[x];
        }

        set<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.insert(i);
            }
        }

        vector<pii> edges;
        for (int u : a) {
            int v = *begin(leaves);
            leaves.erase(begin(leaves));

            if (u < v) {
                edges.emplace_back(u, v);
            } else {
                edges.emplace_back(v, u);
            }

            if (--degree[u] == 1) {
                leaves.insert(u);
            }
        }

        edges.emplace_back(*begin(leaves), n - 1);
        sort(all(edges));
        for (auto& p : edges) {
            cout << (p.first + 1) << ' ' << (p.second + 1) << '\n';
        }
    }

    return 0;
}
