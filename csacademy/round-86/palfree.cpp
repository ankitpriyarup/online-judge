#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MAXN = 503;
constexpr int INF = 1e8;
string s;
int dp[MAXN][2][2];

int solve(int p, bool ch1, bool ch0) {
    // minimum number of changes to change up to p given
    // you must change 1 or 2 respectively
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return ch0;
    }
    if (!ch1 and !ch0 and s[p] == s[p - 1]) {
        return INF;
    }

    if (dp[p][ch1][ch0] != -1) {
        return dp[p][ch1][ch0];
    }

    int ans = ch0 + solve(p - 1, true, ch1);
    if (s[p] != s[p - 2] or ch0)
        ans = min(ans, ch0 + solve(p - 1, false, ch1));

    return dp[p][ch1][ch0] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    memset(dp, -1, sizeof(dp));

    int n = s.size();
    int ans = n;
    for (int k = 0; k < 2; ++k) {
        for (int l = 0; l < 2; ++l) {
            ans = min(ans, solve(n - 1, k, l));
        }
    }
    printf("%d\n", ans);

    return 0;
}
