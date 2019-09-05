#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 20004;
constexpr int MAXK = 11;
int k;
ll a[MAXN];
ll b[MAXK];
ll p[MAXN];
bool dp[MAXN][1 << MAXK];
bool done[MAXN][1 << MAXK];

bool solve(int n, int mask) {
    if (mask == 0) return true;
    if (n == 0) return false;
    if (done[n][mask]) return dp[n][mask];

    for (int j = 0; j < k; ++j) {
        if ((mask & (1 << j)) == 0) continue;

        // p[n] - p[i] >= b[j]
        // p[n] - b[j] >= p[i]
        int idx = upper_bound(p, p + n, p[n] - b[j]) - p;
        --idx;
        if (idx < 0) continue;

        // cout << "j = " << j << " b[j] = " << b[j] << '\n';
        // cout << "p[n] = " << p[n] << " p[idx] " << p[idx] << '\n';
        assert(p[n] - p[idx] >= b[j]);
        if (idx < n) {
            dp[n][mask] |= solve(idx, mask ^ (1 << j));
        }
    }

    /*
    for (int i = 0; !dp[n][mask] and i < n; ++i) {
        ll sum = p[n] - p[i];
        for (int j = 0; !dp[n][mask] and j < k; ++j) {
            if ((mask & (1 << j)) > 0 and sum >= b[j]) {
                dp[n][mask] |= solve(i, mask ^ (1 << j));
            }
        }
    }
    */

    done[n][mask] = true;
    return dp[n][mask];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = a[i] + p[i - 1];
    }
    /*
    for (int i = 0; i <= n; ++i)
        cout << p[i] << ' ';
    cout << '\n';
    */

    for (int i = 0; i < k; ++i)
        cin >> b[i];
    
    bool res = solve(n, (1 << k) - 1);
    if (res) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
