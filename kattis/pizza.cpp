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
int grid[MAXN][MAXN];
int x[MAXN], y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %d", &m, &n);
        memset(grid, 0, sizeof(grid));
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &grid[i][j]);
                x[i] += grid[i][j];
                y[j] += grid[i][j];
            }
        }

        // score(x, y) = sum f(x', y') * (|x - x'| + |y - y')
        // score(x, y) = sum f(x', y') * |x - x'| + sum f(x', y') * |y - y'|
        // score(x, y) = sum f(x', _) * |x - x'| + sum f(_, y') * |y - y'|

        int min_x = 1e9;
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = 0; j < n; ++j) {
                cur += abs(i - j) * x[j];
            }

            min_x = min(min_x, cur);
        }

        int min_y = 1e9;
        for (int i = 0; i < m; ++i) {
            int cur = 0;
            for (int j = 0; j < m; ++j) {
                cur += abs(i - j) * y[j];
            }

            min_y = min(min_y, cur);
        }

        printf("%d blocks\n", min_x + min_y);
    }
    
    return 0;
}
