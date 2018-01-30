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

constexpr int INF = 1e8;
int n, h, w, moves;
int gx, gy;
char grid[15][15];
int ans = INF;

constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, -1, 0, 1};

bool safe(const vector<int>& pos, int i, int x, int y) {
    bool found = false;
    for (int p = 0; p < n; ++p) {
        if (p == i) continue;
        found |= pos[2 * p] == x and pos[2 * p + 1] == y;
    }

    return !found and 0 <= x and x < h and 0 <= y and y < w and grid[x][y] != 'W';
}

vector<int> do_move(const vector<int>& pos, int p, int d) {
    int nx = pos[2 * p] + dx[d];
    int ny = pos[2 * p + 1] + dy[d];
    while (safe(pos, p, nx, ny)) {
        nx += dx[d];
        ny += dy[d];
    }

    nx -= dx[d];
    ny -= dy[d];

    vector<int> res(begin(pos), end(pos));
    res[2 * p] = nx;
    res[2 * p + 1] = ny;

    return res;
}

map<vector<int>, int> memo;

void dfs(const vector<int>& pos, int depth) {
    if (pos[0] == gx and pos[1] == gy) {
        ans = min(ans, depth);
    }

    if ((memo.find(pos) != end(memo) and memo[pos] <= depth) or depth >= moves) {
        return;
    }

    /*
    for (int x = 0; x < depth; ++x)
        printf("\t");
    printf("%d | ", depth);
    for (int i = 0; i < n; ++i) {
        printf("(%d, %d) ", pos[2 * i], pos[2 * i + 1]);
    }
    printf("\n");
    */

    memo[pos] = depth;
    if (pos[0] == gx and pos[1] == gy) {
        return;
    }

    // const vector<int> target = {3, 3, 3, 0};

    for (int p = 0; p < n; ++p) {
        for (int d = 0; d < 4; ++d) {
            vector<int> new_pos = do_move(pos, p, d);

            /*
            if (pos == target) {
                for (int i = 0; i < n; ++i) {
                    printf("(%d, %d) ", new_pos[2 * i], new_pos[2 * i + 1]);
                }
                printf("\n");
            }
            */

            dfs(new_pos, depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d %d", &n, &w, &h, &moves);
    for (int i = 0; i < h; ++i) {
        scanf("%s", grid[i]);
    }

    vector<int> pos(2 * n);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] >= '0' and grid[i][j] <= '9') {
                int p = grid[i][j] - '1';
                pos[2 * p] = i;
                pos[2 * p + 1] = j;

                grid[i][j] = '.';
            } else if (grid[i][j] == 'X') {
                gx = i;
                gy = j;

                grid[i][j] = '.';
            }
        }
    }

    ans = INF;
    dfs(pos, 0);

    if (ans == INF) {
        printf("NO SOLUTION\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}
