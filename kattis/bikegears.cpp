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
    vi f(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector<pii> gears;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            gears.emplace_back(f[i], b[j]);
        }
    }

    sort(all(gears), [](const pii& g0, const pii& g1) {
        int f0, b0, f1, b1;
        tie(f0, b0) = g0;
        tie(f1, b1) = g1;
        ll l = 1LL * f0 * b1;
        ll r = 1LL * f1 * b0;
        if (l == r) {
            return f0 < f1;
        }

        return l < r;
    });

    for (auto& g : gears) {
        cout << "(" << g.first << "," << g.second << ")\n";
    }
    
    return 0;
}
