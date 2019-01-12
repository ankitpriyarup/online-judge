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
    cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x == 1) ++a;
        else if (x == 2) ++b;
        else ++c;
    }

    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, 0.0)));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (i + j + k == 0)
                    continue;

                double full = i + j + k;
                double ev = n / full - 1.0;
                dp[i][j][k] = ev;
                if (i and j < n)
                    dp[i][j][k] += i / full * (1.0 + dp[i - 1][j + 1][k]);
                if (j and k < n)
                    dp[i][j][k] += j / full * (1.0 + dp[i][j - 1][k + 1]);
                if (k)
                    dp[i][j][k] += k / full * (1.0 + dp[i][j][k - 1]);
            }
        }
    }

    cout << setprecision(10) << fixed << dp[c][b][a] << '\n';
    
    return 0;
}
