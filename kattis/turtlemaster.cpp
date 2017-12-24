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

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

char grid[10][10];
int n;
char moves[100];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 8; ++i) {
        scanf("%s", grid[i]);
    }

    scanf("%s", moves);
    int n = strlen(moves);

    int x = 7;
    int y = 0;
    int d = 0;
    for (int i = 0; i < n; ++i) {
        // printf("%d %d %d\n", x, y, d);
        if (moves[i] == 'F') {
            x += dx[d];
            y += dy[d];
            if (!(0 <= x and x < 8 and 0 <= y and y < 8 and grid[x][y] != 'C' and grid[x][y] != 'I')) {
                return printf("%s\n", "Bug!"), 0;
            }
        } else if (moves[i] == 'L') {
            d = (d + 3) & 3;
        } else if (moves[i] == 'R') {
            d = (d + 1) & 3;
        } else {
            x += dx[d];
            y += dy[d];
            if (!(0 <= x and x < 8 and 0 <= y and y < 8 and grid[x][y] == 'I')) {
                return printf("%s\n", "Bug!"), 0;
            }

            grid[x][y] = '.';
            x -= dx[d];
            y -= dy[d];
        }
    }

    if (grid[x][y] != 'D')
        return printf("%s\n", "Bug!"), 0;
    else
        return printf("%s\n", "Diamond!"), 0;

    return 0;
}
