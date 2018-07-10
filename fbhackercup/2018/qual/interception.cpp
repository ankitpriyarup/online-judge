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

void solve() {
    /* 
     * p0 * x ^ 0 => (p0 * x) ^ 0 => Always 1
     *
     * p1 * x ^ 1 + p0 * x ^ 0
     * p1 * x ^ (1 + p0) * x ^ 0
     * (p1 * x) ^ ((1 + p0) * x) ^ 0
     * (p1 * x) ^ (((1 + p0) * x) ^ 0)
     * (p1 * x) ^ (1)
     * (p1 * x) => 0 iff x == 0
     *
     * p2 * x ^ 2 + p1 * x ^ 1 + p0 * x ^ 0
     * p2 * x ^ (2 + p1) * x ^ (1 + p0) * x ^ 0
     * (p2 * x) ^ ((2 + p1) * x) ^ ((1 + p0) * x) ^ 0
     * (p2 * x) ^ (((2 + p1) * x) ^ 1)
     * (p2 * x) ^ ((2 + p1) * x) Never 0.
     *
     * p3 * x ^ 3 + p2 * x ^ 2 + p1 * x ^ 1 + p0 * x ^ 0
     * p3 * x ^ (3 + p2) * x ^ (2 + p1) * x ^ (1 + p0) * x ^ 0
     * (p3 * x) ^ ((3 + p2) * x) ^ ((2 + p1) * x) ^ ((1 + p0) * x) ^ 0
     * 0 ^ 0 ^ 0 ^ 0 ^ 0
     */
    int n;
    scanf(" %d", &n);
    int x;
    for (int i = 0; i <= n; ++i) {
        scanf(" %d", &x);
    }

    if (n % 2 == 1) {
        printf("1\n0.0\n");
    } else {
        printf("0\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        printf("Case #%d: ", tc);
        solve();
    }

    return 0;
}
