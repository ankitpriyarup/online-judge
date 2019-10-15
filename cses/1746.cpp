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
    int seed;
    cin >> seed;

    vi dp(m + 1, 0);
    if (seed == 0) {
        dp.assign(m + 1, 1);
    } else {
        dp[seed] = 1;
    }

    dp[0] = 0;

    constexpr int MOD = 1e9 + 7;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        vi ndp(m + 1, 0);
        if (x == 0) {
            for (x = 1; x <= m; ++x) {
                for (int nx = x - 1; nx <= x + 1; ++nx) {
                    if (0 < nx and nx <= m) {
                        ndp[x] += dp[nx];
                        if (ndp[x] >= MOD)
                            ndp[x] -= MOD;
                    }
                }
            }
        } else {
            for (int nx = x - 1; nx <= x + 1; ++nx) {
                if (0 < nx and nx <= m) {
                    ndp[x] += dp[nx];
                    if (ndp[x] >= MOD)
                        ndp[x] -= MOD;
                }
            }
        }

        swap(dp, ndp);
    }

    int sum = 0;
    for (int x : dp) {
        sum += x;
        if (sum >= MOD)
            sum -= MOD;
    }

    cout << sum << '\n';
    
    return 0;
}
