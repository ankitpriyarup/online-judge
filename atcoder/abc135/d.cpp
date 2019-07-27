#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;
int sum(int a, int b, int mod=MOD) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }

    return c;
}

inline int prod(int a, int b, int mod=MOD) {
    return (1LL * a * b) % mod;
}

constexpr int MAXN = 1e5 + 5;
int n;
string s;
int dp[MAXN][13];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 13; ++j) {
            if (!dp[i][j]) continue;
            if (s[i] == '?') {
                for (int k = 0; k < 10; ++k) {
                    int v = (10 * j + k) % 13;
                    dp[i + 1][v] = sum(dp[i + 1][v], dp[i][j]);
                }
            } else {
                int v = (10 * j + s[i] - '0') % 13;
                dp[i + 1][v] = sum(dp[i + 1][v], dp[i][j]);
            }
        }
    }

    cout << dp[n][5] << '\n';
    
    return 0;
}
