#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200000;
constexpr int BASE[] = {223, 163, 271};
constexpr int MOD = 1e9 + 9;
ll p[MAXN][2];

int solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i][0] >> p[i][1];
    }

    if (n < 3) return 0;

    int s = 1;

    vi f(3 * n + 1);
    f[n] = 0;

    vi inds(n);
    iota(all(inds), 0);
    for (int v = 0; v < 2; ++v) {
        for (int idx = 0; idx < n; ++idx) {
            int i = inds[idx];
            int j = inds[(idx + 1) % n];
            int k = inds[(idx + n - 1) % n];
            ll dx1 = p[j][0] -  p[i][0];
            ll dy1 = p[j][1] -  p[i][1];

            ll dx2 = p[k][0] -  p[i][0];
            ll dy2 = p[k][1] -  p[i][1];

            ll dist = (dx1 * dx1 + dy1 * dy1) % MOD;
            ll dot = (dx1 * dx2 + dy1 * dy2) % MOD;
            ll cross = ((dx1 * dy2 - dx2 * dy1) * s + MOD) % MOD;

            int hash = (BASE[0] * dist + BASE[1] * dot + BASE[2] * cross) % MOD;
            if (v == 0) {
                f[idx] = hash;
            } else {
                f[n + 1 + idx] = hash;
                f[n + n + 1 + idx] = hash;
            }
        }

        for (int i = 1; i < n; ++i) {
            inds[i] = n - i;
        }
        s = -s;
    }

    int ans = 0;

    // z algo
    vi z(f.size());
    int l = -1, r = -1;
    for (int i = 1; i < f.size(); ++i) {
        z[i] = (i >= r) ? 0 : min(r - i, z[i - l]);
        while (i + z[i] < f.size() and f[i + z[i]] == f[z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i, r = i + z[i];
        }

        if (i > n and z[i] >= n) {
            ++ans;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int m;
        cin >> m;
        int best = 0;
        int best_freq = 0;
        for (int poly = 0; poly < m; ++poly) {
            int x = solve();
            if (x > best) {
                best = x;
                best_freq = 1;
            } else if (x == best) {
                ++best_freq;
            }

            cout << x << '\n';
        }

        cout << best << ' ' << best_freq << '\n';
    }
    
    return 0;
}
