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
    while (cin >> T) {
        if (T == 0) break;
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // 0 cannot make
        // 1 can make by skipping me
        // 2 can make with me
        vector<vi> dp(n + 1, vi(T + 1, 0));

        dp[n][0] = 2;
        int best = 0;
        for (int i = n; i > 0; --i) {
            int v = a[i - 1];
            for (int j = 0; j <= T; ++j) {
                if (j + v <= T and dp[i][j] > 0) {
                    dp[i - 1][j + v] = 2;
                    best = max(best, j + v);
                }
                if (dp[i][j] > 0) {
                    dp[i - 1][j] = max(dp[i - 1][j], 1);
                }
            }
        }

        int cur = best;
        for (int i = 0; i < n; ++i) {
            if (dp[i][cur] == 2) {
                cout << a[i] << ' ';
                cur -= a[i];
            }
        }

        cout << best << '\n';
    }
    
    return 0;
}
