#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int INF = 1e9 + 7;
int n, m;
vi f;
vector<vector<vi>> dp;
int base;
// j - number of | from 1 below
// k - number of | from 2 below
int go(int i, int j, int k) {
   //  cout << "go(" << (i + base + 1) << ", " << j << ", " << k << ")\n";
    if (base + i == m or f[base + i] == 0) {
        int res = (j + k) == 0 ? 0 : -INF;
       //  cout << "base case. res = " << res << '\n';
        return res;
    }
    int taken = j + k;
    if (taken > f[base + i]) {
        // cout << "used too many. -INF\n";
        return -INF;
    }

    auto& res = dp[i][j][k];
    if (res != -INF)
        return res;

    for (int take = 0; take < 3 and taken + take <= f[base + i]; ++take) {
        int horiz = (f[base + i] - taken - take) / 3;
        // cout << "vert, horiz: " << take << ", " << horiz << '\n';
        res = max(res, take + go(i + 1, take, j) + horiz); 
    }

    // cout << "go(" << (i + base + 1) << ", " << j << ", " << k << ") = " << res << "\n";
    if (res == INF)
        --res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    f.resize(m);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        ++f[x];
    }

    /*
    for (int i = 0; i < m; ++i) {
        cout << "f[" << (i + 1) << "] = " << f[i] << '\n';
    }
    */

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (f[i] == 0) continue;

        int j = i + 1;
        while (j < m and f[j] > 0) {
            ++j;
        }

        dp.assign(j - i, vector<vi>(3, vi(3, -INF)));
        // cout << "Handle range " << (i + 1) << " to " << (j + 1) << '\n';
        base = i;
        ans += go(0, 0, 0);
        i = j;
    }

    cout << ans << '\n';

    return 0;
}
