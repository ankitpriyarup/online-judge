#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 17;

int n, c, m;
int cost[MAXN];
int percent[MAXN];

// dp[mask][j][k] = probability you can get k people from mask with money j
double dp[1 << MAXN][MAXN];

void read() {
    scanf("%d %d %d", &n, &c, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", cost + i, percent + i);
    }

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = -1.0;
        }
    }
}

long double solve(int mask, int remaining, int money) {
    if (remaining == 0) {
        return 1.0;
    }
    if (mask == 0) {
        return 0.0;
    }

    if (dp[mask][remaining] >= 0.0) {
        return dp[mask][remaining];
    }

    dp[mask][remaining] = 0.0;
    for (int person = 0; person < n; ++person) {
        int new_mask = mask & ~(1 << person);
        int new_cost = money - cost[person];

        if (new_mask != mask and new_cost >= 0) {
            double exp_succ = percent[person] * solve(new_mask, remaining - 1, new_cost);
            double exp_fail = (100 - percent[person]) * solve(new_mask, remaining, new_cost);

            dp[mask][remaining] = max(dp[mask][remaining], (exp_succ + exp_fail) / 100.0);
        }
    }

    return dp[mask][remaining];
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        read();
        long double ans = solve((1 << n) - 1, c, m);

        printf("%.9Lf\n", ans);
    }

    return 0;
}
