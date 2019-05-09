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

    int k;
    cin >> k;
    vector<char> symbols(k);
    vi inv(26, -1);
    for (int i = 0; i < k; ++i) {
        cin >> symbols[i];
        inv[symbols[i] - 'a'] = i;
    }

    vector<vi> costs(k, vi(k, 0));
    vector<vi> res(k, vi(k, -1));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            string s;
            cin >> s;
            res[i][j] = inv[s.back() - 'a'];
            s.pop_back();
            s.pop_back();
            costs[i][j] = stoi(s);
        }
    }

    constexpr int INF = 1e9;
    int T;
    cin >> T;
    while (T-- > 0) {
        string s;
        cin >> s;
        int n = s.size();

        vector<vector<vi>> dp(n, vector<vi>(n, vi(k, INF)));
        for (int i = 0; i < n; ++i) {
            dp[i][i][inv[s[i] - 'a']] = 0;
        }

        for (int sz = 2; sz <= n; ++sz) {
            for (int l = 0; l + sz <= n; ++l) {
                int r = l + sz - 1;
                for (int m = l + 1; m <= r; ++m) {
                    for (int a = 0; a < k; ++a) {
                        for (int b = 0; b < k; ++b) {
                            int c = res[a][b];
                            dp[l][r][c] = min(dp[l][r][c], dp[l][m - 1][a] + dp[m][r][b] + costs[a][b]);
                        }
                    }
                }
            }
        }

        int symb = -1;
        int best = INF;
        for (int c = 0; c < k; ++c) {
            if (dp[0][n - 1][c] < best) {
                best = dp[0][n - 1][c];
                symb = c;
            }
        }

        cout << best << "-" << symbols[symb] << '\n';
    }

    int junk;
    cin >> junk;
    
    return 0;
}
