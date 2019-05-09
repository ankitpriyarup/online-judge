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
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    constexpr int MAXV = 100 * 100;
    vector<vi> dp(n + 1, vi(2 * MAXV, 0));
    dp[n][0 + MAXV] = true;
    for (int i = n; i; --i) {
        for (int j = -MAXV; j < MAXV; ++j) {
            if (!dp[i][j + MAXV]) continue;
            dp[i - 1][j + MAXV + a[i - 1]] = 1;
            dp[i - 1][j + MAXV - b[i - 1]] = 1;
        }
    }

    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = -10; j <= 10; ++j) {
            cout << dp[i][j + MAXV];
        }
        cout << '\n';
    }
    */

    int goal = MAXV;
    for (int j = -MAXV; j < MAXV; ++j) {
        if (dp[0][j + MAXV]) {
            goal = min(goal, abs(j));
        }
    }

    auto walk = [&](int g) {
        string res(n, 'A');
        if (dp[0][g + MAXV] == 0) {
            res[0] = 'C';
            return res;
        }

        for (int i = 0; i < n; ++i) {
            // cout << "i g " << i << " " << g << '\n';
            if (dp[i + 1][g + MAXV - a[i]]) {
                g -= a[i];
            } else {
                res[i] = 'B';
                g += b[i];
            }
        }

        return res;
    };

    string s = min(walk(-goal), walk(goal));
    cout << s << '\n';

    return 0;
}
