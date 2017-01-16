#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX_V = 1000000;
int n, k;

int values[20004];
int sieve[MAX_V + 6];

void gen_sieve() {
    memset(sieve, -1, sizeof(sieve));
    sieve[0] = 0;
    sieve[1] = 0;

    for (int i = 2; i <= MAX_V; ++i) {
        if (sieve[i] == -1) {
            for (int j = i; j <= MAX_V; j += i) {
                sieve[j] = i;
            }
        }
    }
}

// dp[i][j] = best score using numbers up to i and j regions
// i >= j - 1
int dp[20004][101];
// status[i][j] = the gcd of the last region for dp[i][j]
int status[20004][101];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    gen_sieve();

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &values[i]);
    }

    /*
       10 5 4 8 3

    1:  5 5 0 0 0
    2: -1 5 2 2 0
    3: -1 - 2 2 2
    */

    memset(dp, -1, sizeof(dp));
    memset(status, 0, sizeof(status));

    dp[0][1] = sieve[values[0]];
    status[0][1] = values[0];

    for (int i = 1; i < n; ++i) {
        status[i][1] = gcd(status[i - 1][1], values[i]);
        dp[i][1] = sieve[status[i][1]];
    }

    for (int j = 2; j <= k; ++j) {
        status[j - 1][j] = values[j - 1];
        dp[j - 1][j] = min(dp[j - 2][j - 1], sieve[values[j - 1]]);

        for (int i = j; i < n; ++i) {
            // extend the current partition
            int status1 = gcd(status[i - 1][j], values[i]);
            int score1 = min(dp[i - 1][j], sieve[status1]);

            // Create a new partition
            int score2 = min(dp[i - 1][j - 1], sieve[values[i]]);
            int status2 = values[i];

            if (score1 > score2) {
                dp[i][j] = score1;
                status[i][j] = status1;
            } else {
                dp[i][j] = score2;
                status[i][j] = status2;
            }
        }
    }

    /*
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i < n; ++i) {
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }
    */

    printf("%d\n", dp[n - 1][k]);
    return 0;
}
