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

char a[10], b[10];
int n, m;

char board[100][100];

void draw_box(int cx, int cy, int val) {
    for (int i = cx - 2; i <= cx + 2; ++i) {
        for (int j = cy - 2; j <= cy + 2; ++j) {
            board[i][j] = ' ';
        }
        board[i][cy - 2] = '|';
        board[i][cy + 2] = '|';
    }
    for (int j = cy - 2; j <= cy + 2; ++j) {
        board[cx - 2][j] = '-';
        board[cx + 2][j] = '-';
    }

    for (int dx = -2; dx <= 2; dx += 4) {
        for (int dy = -2; dy <= 2; dy += 4) {
            board[cx + dx][cy + dy] = '+';
        }
    }

    board[cx][cy] = '/';
    board[cx + 1][cy - 1] = '/';
    board[cx - 1][cy + 1] = '/';
    board[cx + 1][cy + 1] = (val % 10) + '0';
    board[cx - 1][cy - 1] = (val / 10) + '0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf("%s %s", a, b) == 2) {
        n = strlen(a);
        m = strlen(b);

        if (a[0] == '0' and b[0] == '0')
            break;

        memset(board, 0, sizeof(board));

        int width = 5 + 4 * n;
        int height = 5 + 4 * m;

        // Draw the outline
        for (int i = 0; i < height; ++i) {
            board[i][0] = '|';
            for (int j = 1; j < width; ++j)
                board[i][j] = ' ';

            board[i][width - 1] = '|';
        }

        for (int j = 0; j < width; ++j) {
            board[0][j] = '-';
            board[height - 1][j] = '-';
        }

        board[0][0] = board[0][width - 1] = board[height - 1][0] = board[height - 1][width - 1] = '+';

        // Draw the inner boxes
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = 4 + 4 * i;
                int y = 4 + 4 * j;

                draw_box(x, y, (b[i] - '0') * (a[j] - '0'));
            }
        }

        // draw a and b
        for (int i = 0; i < n; ++i) {
            int y = 4 + 4 * i;
            board[1][y] = a[i];
        }

        for (int j = 0; j < m; ++j) {
            int x = 4 + 4 * j;
            board[x][width - 2] = b[j];
        }

        int v1 = atoi(a);
        int v2 = atoi(b);
        int res = v1 * v2;

        for (int j = n - 1; res > 0 and j >= 0; --j) {
            int x = height - 2;
            int y = 3 + 4 * j;
            board[x][y] = (res % 10) + '0';
            board[x][y + 2] = '/';
            res /= 10;
        }

        board[height - 2][3 + 4 * (n - 1) + 2] = ' ';

        for (int i = m - 1; res > 0 and i >= 0; --i) {
            int x = 5 + 4 * i;
            int y = 1;
            board[x][y] = (res % 10) + '0';
            board[x + 2][y] = '/';
            res /= 10;
        }

        for (int i = 0; i < height; ++i) {
            printf("%s\n", board[i]);
        }
    }
    
    return 0;
}
