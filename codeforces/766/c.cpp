#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1003;
const int SIGMA = 26;
const int MOD = 1e9 + 7;
int n;
char s[MAXN];

int a[SIGMA];
bool freq[SIGMA];

// dp[0] = # of ways to split
// dp[1] = longest substring over all ways
// dp[2] = min # of substrings over all ways
int dp[3][MAXN];

inline int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD) {
        c -= MOD;
    }

    return c;
}

bool valid(int len) {
    for (int i = 0; i < SIGMA; ++i) {
        if (freq[i] and len > a[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    scanf("%d %s", &n, s);

    for (int i = 0; i < SIGMA; ++i) {
        scanf("%d", a + i);
    }

    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[2][0] = 0;

    for (int i = 1; i <= n; ++i) {
        memset(freq, 0, sizeof(freq));
        dp[0][i] = 0;
        dp[1][i] = 1;
        dp[2][i] = MOD;
        for (int j = i - 1; j >= 0; --j) {
            // consider the substring [j, i)
            freq[s[j] - 'a'] = true;
            if (!valid(i - j)) {
                break;
            }

            dp[0][i] = sum(dp[0][i], dp[0][j]);
            dp[1][i] = max(dp[1][i], max(i - j, dp[1][j]));
            dp[2][i] = min(dp[2][i], 1 + dp[2][j]);
        }

        // printf("%d: %d %d %d\n", i, dp[0][i], dp[1][i], dp[2][i]);
    }

    printf("%d\n%d\n%d\n", dp[0][n], dp[1][n], dp[2][n]);

    return 0;
}
