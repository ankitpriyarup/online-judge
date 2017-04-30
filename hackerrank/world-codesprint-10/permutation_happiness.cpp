#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 3003;
const int MOD = 1000000007;

// dp[i][j] = # of permutations of length i with exactly j valleys
// \/ or v ????
int dp[MAXN][MAXN];

inline int sum(const int& a, const int& b) {
    int c = a + b;
    while (c < 0) {
        c += MOD;
    }

    while (c >= MOD) {
        c -= MOD;
    }

    return c;
}

inline int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}

int modpow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp) {
            res = prod(res, cur);
        }

        cur = prod(cur, cur);
    }

    return res;
}

void gen_dp() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < MAXN; ++i) {
        dp[i][0] = modpow(2, i - 1);
    }
    
    // Recurrence taken from page 5 of https://arxiv.org/pdf/math/0005180.pdf
    for (int i = 2; i < MAXN; ++i) {
        for (int j = 1; j < i; ++j) {
            int first = prod(prod(2, j + 1), dp[i - 1][j]);
            int second = prod(sum(i, -prod(2, j)), dp[i - 1][j - 1]);
            dp[i][j] = sum(first, second);
        }
    }
}

int main() {
    int q;
    scanf("%d", &q);
    gen_dp();
    
    while (q-- > 0) {
        int n, k;
        scanf("%d %d", &n, &k);
        
        int ans = 0;
        for (int j = k; j < n; ++j) {
            ans = sum(ans, dp[n][n - 1 - j]);
        }
        
        printf("%d\n", ans);
    }
    return 0;
}
