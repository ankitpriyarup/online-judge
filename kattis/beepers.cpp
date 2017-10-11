#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 22;
constexpr int MAXB = 15;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
int b;
int p[MAXB][2];
ll dp[1 << MAXB][MAXB];

void read() {
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &p[0][0], &p[0][1]);
    scanf("%d", &b);
    ++b;
    for (int i = 1; i < b; ++i) {
        scanf("%d %d", &p[i][0], &p[i][1]);
    }
}

inline ll dist(int i, int j) {
    return abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
}

void solve() {
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << b); ++mask) {
        for (int i = 0; i < b; ++i) {
            if (dp[mask][i] == INF or (mask & (1 << i)) == 0) {
                continue;
            }

            for (int j = 0; j < b; ++j) {
                if ((mask & (1 << j)) != 0) {
                    continue;
                }

                int new_mask = mask | (1 << j);
                ll cost = dp[mask][i] + dist(i, j);
                dp[new_mask][j] = min(dp[new_mask][j], cost);
            }
        }
    }

    int final_mask = (1 << b) - 1;
    ll ans = INF;
    for (int i = 1; i < b; ++i) {
        ans = min(ans, dp[final_mask][i] + dist(i, 0));
    }

    printf("%lld\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        read();
        solve();
    }
    return 0;
}
