#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    string t = "love";
    vll dp(4, 0);
    for (int i = 0; i < n; ++i) {
        vll ndp(4, 0);
        for (int j = 0; j < 4; ++j) {
            ndp[j] += dp[j];
            if (s[i] == t[j]) {
                ndp[j] += (j == 0) ? 1 : dp[j - 1];
            }
        }
        swap(dp, ndp);
    }

    cout << dp.back() << '\n';
    
    return 0;
}
