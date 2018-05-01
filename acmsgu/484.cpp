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

constexpr int MAXN = 222;
int n, m;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf(" %s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'P') {
                x = i;
                y = j;
                grid[i][j] = '.';
            }
        }
    }

    // printf("%d %d\n", x, y);
    while (x < n) {
        if (grid[x][y] == '.')
            ++x;
        else if (grid[x][y] == '/') {
            if (y == 0 or grid[x][y - 1] == '\\') {
                return printf("%d\n", -1), 0;
            }
            ++x;
            --y;
        } else if (grid[x][y] == '\\') {
            if (y == m - 1 or grid[x][y + 1] == '/') {
                return printf("%d\n", -1), 0;
            }
            ++x;
            ++y;
        }
        // printf("%d %d\n", x, y);
    }

    printf("%d\n", y + 1);
    return 0;
}
