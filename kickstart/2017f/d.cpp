#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;

constexpr int MAXN = 10004;
int dp[MAXN];

void precompute() {
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;

    for (int s = 1; s * s <= MAXN; ++s) {
        int bite = s * s;
        for (int j = 0; j < MAXN; ++j) {
            if (j + bite >= MAXN) break;

            if (dp[j] < 10) {
                dp[j + bite] = min(dp[j + bite], dp[j] + 1);
            }
        }
    }
}

int n;
void read() {
    scanf("%d", &n);
}

void solve(int case_num) {
    printf("Case #%d: %d\n", case_num, dp[n]);
}

int main() {
    int T;
    scanf("%d", &T);

    precompute();
    for (int case_num = 1; case_num <= T; ++case_num) {
        read();
        solve(case_num);
    }

    return 0;
}
