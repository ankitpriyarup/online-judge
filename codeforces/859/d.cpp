#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 7;
int n;
ld p[1 << MAXN][1 << MAXN];
// Probability team i wins up to round j
ld prob[1 << MAXN][MAXN];

// dp[i][j] = expected value if you have a bracket culminating in team i winning the first j levels
ld dp[1 << MAXN][MAXN];

inline void get_opps(int round, int team, int& start, int& end) {
    int block_size = 1 << (round - 1);
    int block_id = team / block_size;

    if ((block_id & 1) == 0) {
        start = (block_id + 1) * block_size;
        end = (block_id + 2) * block_size;
    } else {
        start = (block_id - 1) * block_size;
        end = block_id * block_size;
    }
}

int main() {
    scanf("%d", &n);
    int teams = (1 << n);

    int x;
    for (int i = 0; i < teams; ++i) {
        for (int j = 0; j < teams; ++j) {
            scanf("%d", &x);
            p[i][j] = x / 100.0L;
        }
    }
    for (int team = 0; team < teams; ++team) {
        prob[team][0] = 1.0L;
        dp[team][0] = 0.0L;
    }

    for (int round = 1; round <= n; ++round) {
        // the probability that a team wins in round i is
        // the probability they win in round i - 1 times
        // the weighted probability they beat any opponent
        for (int team = 0; team < teams; ++team) {
            ld weighted = 0;
            int start, end;
            get_opps(round, team, start, end);

            // printf("In round %d, team %d opponents range from %d to %d\n", round, team, start, end);
            for (int opp = start; opp < end; ++opp) {
                weighted += prob[opp][round - 1] * p[team][opp];
            }

            prob[team][round] = prob[team][round - 1] * weighted;
            // printf("prob[%d][%d] = %.3Lf\n", team, round, prob[team][round]);
        }
    }

    for (int round = 1; round <= n; ++round) {
        for (int team = 0; team < teams; ++team) {
            ld& val = dp[team][round];
            val = 0.0L;

            int start, end;
            get_opps(round, team, start, end);

            for (int opp = start; opp < end; ++opp) {
                val = max(val, dp[team][round - 1] + dp[opp][round - 1] + prob[team][round] * (1 << (round - 1)));
            }

            // printf("dp[%d][%d] = %.3Lf\n", team, round, dp[team][round]);
        }
    }

    ld ans = 0;
    for (int team = 0; team < teams; ++team) {
        ans = max(ans, dp[team][n]);
    }
    printf("%.12Lf\n", ans);

    return 0;
}
