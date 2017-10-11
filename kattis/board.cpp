#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 35;
int n, m;
char grid[MAXN][MAXN];

bool un_stamp(int x, int y) {
    int red = 0;
    int green = 0;
    int blue = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            switch (grid[x + dx][y + dy]) {
                case 'R':
                    ++red;
                    break;
                case 'G':
                    ++green;
                    break;
                case 'B':
                    ++blue;
                    break;
                case 'W':
                    return false;
            }
        }
    }

    int sum = red + green + blue;
    bool changed = (red == sum or green == sum or blue == sum) and sum > 0;
    if (changed) {

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                grid[x + dx][y + dy] = '?';
            }
        }
    }

    return changed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (un_stamp(i, j)) {
                    changed = true;
                }
            }
        }
    }

    bool safe = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != 'W' and grid[i][j] != '?') {
                safe = false;
            }
        }
    }

    printf("%s\n", safe ? "YES" : "NO");
    
    return 0;
}
