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

constexpr int MAXN = 111;
int n, m;
char grid[MAXN][MAXN];
int uf[MAXN * MAXN];

int find(int x) {
    return uf[x] = (uf[x] == x) ? x : find(uf[x]);
}

bool merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return 0;
    uf[xr] = yr;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    for (int i = 0; i < n * m; ++i) {
        uf[i] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') continue;

            ++ans;
            int ind1 = m * i + j;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (!dx and !dy) continue;

                    int nx = i + dx;
                    int ny = j + dy;
                    if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] == '#') {
                        int ind2 = m * nx + ny;
                        ans -= merge(ind1, ind2);
                    }
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
