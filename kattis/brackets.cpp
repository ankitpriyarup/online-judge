#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 5005;
struct block {
    int sum, min_pref;
    block(): sum(0), min_pref(0) {}
    block(int sum, int min_pref): sum(sum), min_pref(min_pref) {}

    block operator+(const block& o) const {
        return block{sum + o.sum, min(min_pref, sum + o.min_pref)};
    }

    inline bool valid() const {
        return sum == 0 and min_pref == 0;
    }
} dp[2][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int n;
    n = s.size();

    for (int i = 1; i <= n; ++i) {
        dp[0][i][i] = s[i - 1] == '(' ? block(1, 0) : block(-1, -1);
        dp[1][i][i] = s[i - 1] == ')' ? block(1, 0) : block(-1, -1);
        for (int j = i - 1; j >= 0; --j) {
            dp[0][j][i] = dp[0][j][i - 1] + dp[0][i][i];
            dp[1][j][i] = dp[1][j][i - 1] + dp[1][i][i];
        }
    }
 
    bool valid = dp[0][1][n].valid();
    for (int i = 1; i <= n; ++i) {
        block before = dp[0][0][i - 1];
        for (int j = i; j <= n; ++j) {
            block rev = dp[1][i][j];
            block after = dp[0][j + 1][n];

            if ((before + rev + after).valid()) {
                valid = true;
            }
        }
    }

    cout << (valid ? "possible" : "impossible") << '\n';

    return 0;
}
