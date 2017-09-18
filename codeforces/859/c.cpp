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

constexpr int MAXN = 55;
int n;
int a[MAXN];

pair<int, int> dp[MAXN][2];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    dp[n - 1][0] = {a[n - 1], 0};
    dp[n - 1][1] = {0, a[n - 1]};
    for (int i = n - 2; i >= 0; --i) {
        // Alice take the pie
        pair<int, int> aliceOption1 = {a[i] + dp[i + 1][1].first, dp[i + 1][1].second};

        // Alice don't take the pie
        pair<int, int> aliceOption2 = {dp[i + 1][0].first, a[i] + dp[i + 1][0].second};
        dp[i][0] = aliceOption1.first > aliceOption2.first ? aliceOption1 : aliceOption2;

        // Bob take pie
        pair<int, int> bobOption1 = {dp[i + 1][0].first, a[i] + dp[i + 1][0].second};
        pair<int, int> bobOption2 = {a[i] + dp[i + 1][1].first, dp[i + 1][1].second};
        dp[i][1] = bobOption1.second > bobOption2.second ? bobOption1 : bobOption2;
    }

    printf("%d %d\n", dp[0][1].first, dp[0][1].second);

    return 0;
}
