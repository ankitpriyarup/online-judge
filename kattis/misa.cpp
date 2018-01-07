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

constexpr int MAXN = 100;
int n, m;
char grid[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    int total = 0;
    int extra = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int shakes = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 and dy == 0) {
                        continue;
                    }
                    int nx = i + dx;
                    int ny = j + dy;
                    if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] == 'o')
                        ++shakes;
                }
            }

            if (grid[i][j] == 'o')
                total += shakes;
            else
                extra = max(extra, shakes);
        }
    }

    printf("%d\n", (total >> 1) + extra);
   
    return 0;
}
