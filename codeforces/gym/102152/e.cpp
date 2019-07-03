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
        int n, m;
        cin >> n >> m;
        string s, cost;
        cin >> s >> cost;

        vi dp(26, 10);
        for (int i = 0; i < n; ++i) {
            int x = s[i] - 'a';
            dp[x] = min(dp[x], cost[i] - '0');
        }

        string p;
        cin >> p;
        int ans = 0;
        for (char c : p) {
            if (dp[c - 'a'] == 10) {
                ans = -1;
                break;
            } else {
                ans += dp[c - 'a'];
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}
