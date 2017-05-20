#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INF = 1e8;

class PlusSign {
public:
    int draw(vector<string> v);
};

bool within(int a, int b, int l, int r) {
    return a <= l and l <= r and r < b;
}

int grid[55][55];

int count_rect(int x, int y, int sx, int sy) {
    int ret = grid[x + sx - 1][y + sy - 1];
    ret -= grid[x - 1][y + sy - 1];
    ret -= grid[x + sx - 1][y - 1];
    ret += grid[x - 1][y - 1];

    printf("Rect %d %d %d %d: %d\n", x, y, sx, sy, ret);

    return ret;
}

int count_rect(int x, int y, int size) {
    return count_rect(x, y, size, size);
}

int score(int x, int y, int size, int corner) {
    bool white_corner = count_rect(x, y, corner) == 0;
    white_corner &= count_rect(x + size - corner, y, corner) == 0;
    white_corner &= count_rect(x, y + size - corner, corner) == 0;
    white_corner &= count_rect(x + size - corner, y + size - corner, corner) == 0;

    if (!white_corner) return INF;

    int plus_width = size - 2 * corner;
    int exp_plus = size * size - 4 * corner * corner;

    int ct = count_rect(x + corner, y, plus_width, size);
    ct += count_rect(x, y + corner, size, plus_width);
    ct -= count_rect(x + corner, y + corner, plus_width, plus_width);

    return exp_plus - ct;
}

int PlusSign::draw(vector<string> pixels) {
    int n = pixels.size();
    int m = pixels[0].size();

    int top = n + 1;
    int bot = -1;
    int left = m + 1;
    int right = -1;

    memset(grid, 0, sizeof(grid));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (pixels[i - 1][j - 1] == '#') {
                top = min(top, i);
                bot = max(bot, i);
                left = min(left, j);
                right = max(right, j);
                grid[i][j] = 1;
            }
        }
    }

    // No pixels
    if (bot == -1) {
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            grid[i][j] += grid[i][j - 1];
        }
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            grid[i][j] += grid[i - 1][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%d%c", grid[i][j], j == m ? '\n' : ' ');
        }
    }

    int k = min(n, m);
    int ans = INF;
    for (int size = 3; size <= k; size += 2) {
        for (int x = 1; x + size <= n + 1; ++x) {
            if (!within(x, x + size, top, bot)) continue;
            for (int y = 1; y + size <= m + 1; ++y) {
                if (!within(y, y + size, left, right)) continue;
                for (int c = 1; 2 * c < size; ++c) {
                    int s = score(x, y, size, c);
                    printf("%d %d %d %d: %d\n", x, y, size, c, s);
                    ans = min(ans, s);
                }
            }
        }
    }

    if (ans == INF) {
        return -1;
    } else {
        return ans;
    }
}
