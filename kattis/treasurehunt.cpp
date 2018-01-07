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

constexpr int MAXN = 300;
int r, c;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[MAXN], dy[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i) {
        scanf("%s", grid[i]);
    }

    dx['E'] = 0;
    dx['N'] = -1;
    dx['S'] = 1;
    dx['W'] = 0;

    dy['E'] = 1;
    dy['N'] = 0;
    dy['S'] = 0;
    dy['W'] = -1;

    int x = 0;
    int y = 0;

    int moves = 0;
    while (true) {
        if (x < 0 or y < 0 or x >= r or y >= c)
            return printf("Out\n"), 0;
        if (grid[x][y] == 'T')
            return printf("%d\n", moves), 0;
        if (vis[x][y])
            return printf("Lost\n"), 0;

        vis[x][y] = true;

        int nx = x + dx[grid[x][y]];
        int ny = y + dy[grid[x][y]];
        x = nx;
        y = ny;

        ++moves;
    }

    return 0;
}
