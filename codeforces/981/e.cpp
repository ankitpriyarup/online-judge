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
using query = tuple<int, int, int>;

constexpr int MAXN = 10004;
constexpr int SQRT = 102;

int n, q;
// dp[i][j] = can get weight j at pos i
bitset<MAXN> dp[MAXN];
bitset<MAXN> big[SQRT];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &q);

    for (int i = 0; i < n; ++i)
        dp[i].set(0);

    int l, r, x;
    vector<query> queries;
    for (int i = 0; i < q; ++i) {
        scanf(" %d %d %d", &l, &r, &x);
        --l;
        queries.emplace_back(r - l, l, x);
    }

    sort(begin(queries), end(queries));

    vector<pii> bigs;
    int len;
    for (const auto& quer : queries) {
        tie(len, l, x) = quer;
        int r = l + len;
        for (int p = l; p < r;) {
            if (p % SQRT == 0 && p + SQRT <= r) {
                bigs.emplace_back(p / SQRT, x);
                p += SQRT;
            } else {
                dp[p] |= (dp[p] << x);
                ++p;
            }
        }
    }

    for (int idx = 0; idx < SQRT; ++idx) {
        for (int p = idx * SQRT; p < min(n, (idx + 1) * SQRT); ++p)
            big[idx] |= dp[p];
    }

    int idx;
    for (const auto& p : bigs) {
        tie(idx, x) = p;
        big[idx] |= (big[idx] << x);
    }

    bitset<MAXN> poss;
    for (int p = 0; p < n; ++p) {
        poss |= dp[p];
    }
    for (int idx = 0; idx < SQRT; ++idx) {
        poss |= big[idx];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (poss[i]) ++ans;
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
        if (poss[i])
            printf("%d ", i);
    }

    return 0;
}
