#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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

bool hit[20][20];

pii get_pos(char row, char col) {
    int x = row - 'a' + 2;
    int y = col - '1' + 2;

    return {x, y};
}

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

void do_hit(char c, pii pos) {
    if (c == 'B' or c == 'Q') {
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if ((i + j) == (pos.first + pos.second) or (i - j) == (pos.first - pos.second)) {
                    hit[i][j] = true;
                }
            }
        }
    }

    if (c == 'R' or c == 'Q') {
        for (int i = 0; i < 20; ++i) {
            hit[i][pos.second] = true;
        }

        for (int j = 0; j < 20; ++j) {
            hit[pos.first][j] = true;
        }
    }

    if (c == 'K') {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                hit[pos.first + dx][pos.second + dy] = true;
            }
        }
    }

    if (c == 'N') {
        for (int d = 0; d < 8; ++d) {
            hit[pos.first + dx[d]][pos.second + dy[d]] = true;
        }
    }
}

bool atk(char* a, char* b) {
    memset(hit, 0, sizeof(hit));

    pii ap = get_pos(a[1], a[2]);

    do_hit(a[0], ap);

    pii bp = get_pos(b[1], b[2]);

    return hit[bp.first][bp.second];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);

    char a[10], b[10];

    scanf("%s", a);
    scanf("%s", b);

    int ans = 0;
    if (atk(a, b))
        ans |= 1;
    if (atk(b, a))
        ans |= 2;

    if (ans == 0) {
        puts("NONE");
    } else if (ans == 1) {
        puts("WHITE");
    } else if (ans == 2) {
        puts("BLACK");
    } else {
        puts("BOTH");
    }

    return 0;
}
