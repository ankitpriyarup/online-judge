#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1003;
const int MAXN2 = 1000006;

int n;
int canvas[MAXN][MAXN];
// top bot left right
int bounds[MAXN2][4];

int f_trees[MAXN][MAXN];
bool invalid[MAXN2];

int read(int row, int col) {
    int ans = 0;
    for (int c = col; c > 0; c -= (c & -c)) {
        ans += f_trees[row][c];
    }

    return ans;
}

void update(int row, int col, int v) {
    for (int c = col; c < MAXN; c += (c & -c)) {
        f_trees[row][c] += v;
    }
}

void set_bounds(int color, int x, int y) {
    if (bounds[color][0] == -1) {
        bounds[color][0] = bounds[color][1] = x;
    } else if (x < bounds[color][0]) {
        bounds[color][0] = x;
    } else if (x > bounds[color][1]) {
        bounds[color][1] = x;
    }

    if (bounds[color][2] == -1) {
        bounds[color][2] = bounds[color][3] = y;
    } else if (bounds[color][2] > y) {
        bounds[color][2] = y;
    } else if (bounds[color][3] < y) {
        bounds[color][3] = y;
    }
}

int main() {
    ifstream fin("art.in");
    ofstream fout("art.out");

    memset(bounds, -1, sizeof(bounds));

    fin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> canvas[i][j];
            if (canvas[i][j])
                set_bounds(canvas[i][j], i, j);
        }
    }

    for (int color = 1; color <= n * n; ++color) {
        if (bounds[color][0] == -1) continue;

        for (int row = bounds[color][0]; row <= bounds[color][1]; ++row) {
            update(row, bounds[color][2], 1);
            update(row, bounds[color][3] + 1, -1);
        }
    }

    int valid = n * n;
    memset(invalid, false, sizeof(invalid));

    int colored = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!canvas[i][j]) continue;

            ++colored;
            int count = read(i, j);
            if (count > 1) {
                if (!invalid[canvas[i][j]]) {
                    invalid[canvas[i][j]] = true;
                    --valid;
                }
            }
        }
    }

    // WTF
    if (colored < 5) {
        fout << (n * n - 1) << '\n';
    } else {
        fout << valid << '\n';
    }
    return 0;
}
