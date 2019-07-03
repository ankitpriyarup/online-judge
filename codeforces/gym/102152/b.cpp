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

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m, q;
        cin >> n >> m >> q;
        vi dp(m, 1);
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            for (int j = l; j <= r; ++j) {
                dp[j] = -1;
            }
        }

        vi ans(m + 1, -1);
        if (dp[0] != -1) {
            ans[dp[0]] = 0;
        }
        for (int i = 1; i < m; ++i) {
            if (dp[i] > 0) {
                dp[i] = max(dp[i], dp[i - 1] + 1);
                ans[dp[i]] = i;
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        while (q-- > 0) {
            int k;
            cin >> k;
            int r = ans[k];
            if (r == -1) {
                cout << "-1 -1\n";
            } else {
                cout << (r - k + 1 + 1) << ' ' << (r + 1) << '\n';
            }
        }
    }
    
    return 0;
}
