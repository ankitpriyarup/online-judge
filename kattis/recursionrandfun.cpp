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

int a, b, c;
int dp[102][10004];

int solve(int x, int k) {
    if (x <= 0) {
        return k == 1;
    }

    if (dp[x][k] != -1)
        return dp[x][k];

    int res = false;
    for (int bv = 0; bv < b; ++bv) {
        for (int cv = 0; cv < c; ++cv) {
            res |= solve(x - 1 - cv, k - a - bv);
        }
    }

    return dp[x][k] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, k;
    while (scanf("%d %d %d %d %d", &a, &b, &c, &x, &k) == 5) {
        memset(dp, -1, sizeof(dp));
        printf("%spossible\n", solve(x, k) ? "" : "im");
    }

    return 0;
}
