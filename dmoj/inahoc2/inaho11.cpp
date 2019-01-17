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
    vector<vi> a(m, vi(n));
    constexpr int MOD = 1e9 + 7;
    vi mins(n, MOD + 1), maxs(n, -MOD - 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            mins[j] = min(mins[j], a[i][j]);
            maxs[j] = max(maxs[j], a[i][j]);
        }
    }

    // exclude some dimension, 2 * volume of remaining
    int area = 0;
    for (int i = 0; i < n; ++i) {
        int sub = 1;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            sub = 1LL * sub * (maxs[j] - mins[j]) % MOD;
        }

        area += sub;
        if (area >= MOD)
            area -= MOD;
    }

    area <<= 1;
    if (area >= MOD)
        area -= MOD;
    cout << area << '\n';

    return 0;
}
