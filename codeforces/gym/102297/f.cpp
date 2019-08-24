#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool is_vowel(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    int tc = 1;
    while (T-- > 0) {
        string s;
        cin >> s;

        int n = s.size();
        vector<pair<ll, ll>> dp(n + 1);
        // consonant, vowel
        dp[0] = make_pair(1, 1);

        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '?') {
                dp[i].first = 20LL * dp[i - 1].second;
                dp[i].second = 6LL * dp[i - 1].first;
            } else {
                dp[i].first = dp[i].second = 0;

                if (is_vowel(s[i - 1])) {
                    dp[i].second = dp[i - 1].first;
                } else {
                    dp[i].first = dp[i - 1].second;
                }
            }
        }

        ll ans = dp[n].first + dp[n].second;
        cout << "String #" << tc++ << ": " << ans << '\n' << '\n';
    }

    return 0;
}
