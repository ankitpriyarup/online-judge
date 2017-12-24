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

char grid[10][10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 7; ++i) {
        gets(grid[i]);
    }

    int ans = 0;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                int nnx = nx + dx[d];
                int nny = ny + dy[d];

                //  printf("%d %d %d %d %d %d\n", i, j, nx, ny, nnx, nny);
                if (0 <= nnx and nnx < 7 and 0 <= nny and nny < 7 
                        and grid[i][j] == 'o' and grid[nx][ny] == 'o' and grid[nnx][nny] == '.') {
                    ++ans;
                }
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
