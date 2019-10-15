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

    constexpr int MOD = 1e9 + 7;

    int n;
    cin >> n;
    vi dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        vi ndp(n, 0);
        ndp[0] = row[0] == '.' ? dp[0] : 0;
        for (int j = 1; j < n; ++j) {
            if (row[j] == '.') {
                ndp[j] = ndp[j - 1] + dp[j];
                if (ndp[j] >= MOD)
                    ndp[j] -= MOD;
            }
        }

        swap(dp, ndp);
    }

    cout << dp.back() << '\n';
    
    return 0;
}
