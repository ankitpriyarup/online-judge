#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 2003;
constexpr int MAXK = 29;
constexpr ll INF = numeric_limits<ll>::max();

int n, k;
int a[MAXN];
ll medians[MAXN][MAXN];
ll scores[MAXN][MAXN];
ll dp[MAXK][MAXN];

multiset<int>::iterator last(multiset<int>& ms) {
    return prev(ms.end());
}

void add(ll& lowsum, ll& highsum, multiset<int>& lower, multiset<int>& higher, int x) {
    if (!lower.empty() and x > *last(lower)) {
        higher.insert(x);
        highsum += x;
    } else {
        lower.insert(x);
        lowsum += x;
    }

    while (lower.size() < higher.size()) {
        auto it = begin(higher);
        lowsum += *it;
        highsum -= *it;
        lower.insert(*it);
        higher.erase(it);
    }
    while (lower.size() - 1 > higher.size()) {
        auto it = last(lower);
        highsum += *it;
        lowsum -= *it;
        higher.insert(*it);
        lower.erase(it);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 1; i <= n; ++i) {
        multiset<int> lower;
        multiset<int> higher;
        ll lowsum = 0LL;
        ll highsum = 0LL;
        for (int j = i; j <= n; ++j) {
            add(lowsum, highsum, lower, higher, a[j]);
            ll median = *last(lower);
            scores[i][j] = median * lower.size() - lowsum + highsum - median * higher.size();
            // printf("scores[%d][%d] = %lld\n", i, j, scores[i][j]);
        }
    }

    dp[1][0] = INF;
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = scores[1][i];
    }

    for (int j = 2; j <= k; ++j) {
        for (int i = 1; i <= n; ++i)
            dp[j][i] = dp[j - 1][i];

        for (int i = j; i <= n; ++i) {
            for (int ii = i; ii <= n; ++ii) {
                dp[j][ii] = min(dp[j][ii], dp[j - 1][i - 1] + scores[i][ii]);
            }
        }
    }

    printf("%lld\n", dp[k][n]);

    return 0;
}
