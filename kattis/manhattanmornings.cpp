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

constexpr int MAXN = 1e9 + 7;
map<int, int> f_tree;

void update(int x, int v) {
    x += 1;
    for (; x < MAXN; x += (x & -x)) {
        f_tree[x] = max(f_tree[x], v);
    }
}

int query(int x) {
    x += 1;
    int res = 0;
    for (; x; x -= (x & -x)) {
        res = max(res, f_tree[x]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    int xh, yh, xw, yw;
    scanf(" %d %d %d %d", &xh, &yh, &xw, &yw);
    xw -= xh;
    yw -= yh;
    int sx = 1;
    int sy = 1;
    if (xw < 0) {
        sx = -1;
        xw = -xw;
    }
    if (yw < 0) {
        sy = -1;
        yw = -yw;
    }

    vector<pii> jobs;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf(" %d %d", &x, &y);
        x -= xh;
        y -= yh;
        x *= sx;
        y *= sy;
        if (0 <= x and x <= xw and 0 <= y and y <= yw) {
            jobs.emplace_back(x, y);
        }
    }
    sort(begin(jobs), end(jobs));
    vector<int> dp(jobs.size(), 0);
    int ans = 0;

    for (int i = 0; i < jobs.size(); ++i) {
        int x, y;
        tie(x, y) = jobs[i];
        dp[i] = 1 + query(y);
        update(y, dp[i]);
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);

    return 0;
}
