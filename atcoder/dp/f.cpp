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

    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vi> dp(n + 1, vector<int>(m + 1, 0));
    vector<vi> moves(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i + 1][j + 1] = dp[i][j + 1];
            moves[i + 1][j + 1] = 0;
            if (dp[i + 1][j] > dp[i + 1][j + 1]) {
                moves[i + 1][j + 1] = 1;
                dp[i + 1][j + 1] = dp[i + 1][j];
            }

            if (s[i] == t[j] and dp[i][j] + 1 > dp[i + 1][j + 1]) {
                moves[i + 1][j + 1] = 2;
                dp[i + 1][j + 1] = 1 + dp[i][j];
            }
        }
    }

    string res;
    int i = n;
    int j = m;
    while (i > 0 and j > 0) {
        if (moves[i][j] == 0) {
            --i;
        } else if (moves[i][j] == 1) {
            --j;
        } else {
            --i; --j;
            res.push_back(s[i]);
        }
    }

    reverse(all(res));
    cout << res << '\n';
    
    return 0;
}
