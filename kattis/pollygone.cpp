#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = double;
using pii = pair<int, int>;

constexpr int MAXN = 1003;
constexpr int MAXP = 10004;
constexpr ld EPS = 1e-6;
int n;
int target;
int c[MAXN];
int p[MAXN];

// min energy to hit probability j
int dp[MAXP];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ld dub;
    scanf("%d %lf", &n, &dub);
    target = (10000 * dub) + 0.5;

    /*
    printf("n: %d\n", n);
    printf("target: %d\n", target);
    */

    for (int i = 0; i < n; ++i) {
        scanf("%d %lf", &c[i], &dub);
        p[i] = (10000 * dub) + 0.5;

        // printf("c, p: %d %d\n", c[i], p[i]);
    }

    fill(dp, dp + MAXP, MAXN * MAXN);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 10000; j >= 0; --j) {
            if (j + p[i] < MAXP) {
                dp[j + p[i]] = min(dp[j + p[i]], dp[j] + c[i]);
            }
        }
    }

    int ans = MAXN * MAXN;
    for (int j = target; j <= 10000; ++j) {
        ans = min(ans, dp[j]);
    }


    printf("%d\n", ans);
    return 0;
}
