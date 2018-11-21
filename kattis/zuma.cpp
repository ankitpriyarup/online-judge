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

constexpr int MAXN = 102;
constexpr int MAXK = 6;
constexpr int INF = 1e9 + 7;
int n, k;
int a[MAXN];
vector<int> by_color[MAXN];
int dp[MAXK][MAXN][MAXN];

int solve(int buf, int start, int fin) {
    assert(0 <= start and start <= n);
    assert(0 <= fin and fin <= n);
    assert(start <= fin);
    if (start == fin)
        return 0;

    assert(buf < k);
    int& res = dp[buf][start][fin];
    if (res != -1) {
        return res;
    }

    res = INF;
    if (buf + 1 < k) {
        res = min(res, 1 + solve(buf + 1, start, fin));
    }

    if (buf + 1 == k) {
        res = min(res, solve(0, start + 1, fin));
    }

    for (int i = start + 1; i < fin; ++i) {
        if (a[i] != a[start])
            continue;

        res = min(res, solve(0, start + 1, i) + solve(min(k - 1, buf + 1), i, fin));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &a[i]);
    }
    a[n] = -1;

    memset(dp, -1, sizeof(dp));

    printf("%d\n", solve(0, 0, n));

    return 0;
}
