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
int n, m;
char grid[MAXN][MAXN];
int uf[MAXN * MAXN];

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return 0;
    uf[xr] = yr;
    return 1;
}

inline int f(int x, int y) {
    return x * m + y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc = 0;
    while (scanf(" %d %d", &n, &m) == 2) {
        for (int i = 0; i < n; ++i) {
            scanf(" %s", grid[i]);
        }

        for (int v = 0; v < n * m; ++v) {
            uf[v] = v;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += (grid[i][j] == '-');
                if (i + 1 < n and grid[i][j] == '-' and grid[i + 1][j] == '-') {
                    ans -= merge(f(i, j), f(i + 1, j));
                }
                if (j + 1 < m and grid[i][j] == '-' and grid[i][j + 1] == '-') {
                    ans -= merge(f(i, j), f(i, j + 1));
                }
            }
        }

        printf("Case %d: %d\n", ++tc, ans);
    }
    return 0;
}
