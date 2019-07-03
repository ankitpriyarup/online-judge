#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

/**
 * Brute DP:
 *
 * dp[i][j][k] is can player i win range [j..k] ?
 * dp[i][i][i] = true
 *
 * dp[i][j][k] = l[i][j] and r[i][k]
 * l[i][j] can player i win against the prefix before him to j?
 * possible if there's some player j <= k < i where l[k][j] and r[k][j - 1]
 *
 * Use bitmasks? O(n^3 / 64)? 
 */

using bs = bitset<2000>;
constexpr int MAXN = 2002;
bs a[MAXN];
bs l[MAXN], r[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        l[i].set(i);
        r[i].set(i);
    }

    for (int i = 1; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < i; ++j) {
            if (s[j] == '1') {
                a[i].set(j);
            } else {
                a[j].set(i);
            }
        }
    }
    for (int d = 1; d <= n; ++d) {
        for (int i = 0; i + d < n; ++i) {
            int j = i + d;
            if ((a[j] & l[i] & r[j - 1]).any()) {
                l[i].set(j);
            }
        }

        for (int i = d; i < n; ++i) {
            int j = i - d;
            if ((a[j] & l[j + 1] & r[i]).any()) {
                r[i].set(j);
            }
        }
    }

    int ans = (l[0] & r[n - 1]).count();
    cout << ans << '\n';

    return 0;
}
