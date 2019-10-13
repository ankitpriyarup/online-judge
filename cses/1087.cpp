#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int idx(char c) {
    if (c == 'A')
        return 0;
    else if (c == 'T')
        return 1;
    else if (c == 'C')
        return 2;
    else if (c == 'G')
        return 3;

    assert(false);
    return 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    vector<vi> occ(4);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        occ[idx(s[i])].push_back(i);
    }

    for (int i = 0; i < 4; ++i)
        occ[i].push_back(n);

    vector<vi> dp(n + 1, vi(4, -1));
    vector<vi> previous(n + 1, vi(4, -1));
    int ans = n;
    int lc = -1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            int bef = dp[i - 1][j];
            for (int k = 0; k < 4; ++k) {
                int pos = *upper_bound(all(occ[k]), bef);
                if (pos > dp[i][k]) {
                    dp[i][k] = pos;
                    previous[i][k] = j;
                }
            }
        }

        for (int j = 0; j < 4; ++j) {
            // cout << dp[i][j] << ' ';

            if (dp[i][j] == n) {
                ans = i;
                lc = j;
            }
        }
        // cout << '\n';


        if (ans < n) break;
    }

    string t;
    while (ans > 0) {
        // cout << ans << ' ' << lc << '\n';
        t.push_back("ATCG"[lc]);
        lc = previous[ans][lc];
        --ans;
    }

    reverse(all(t));

    cout << t << '\n';

    return 0;
}
