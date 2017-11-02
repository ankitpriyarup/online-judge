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
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int SIZE = 8;
constexpr int SUM = 260;
constexpr int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
constexpr int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
int board[SIZE][SIZE];
int row_sum[SIZE];
int col_sum[SIZE];
bool solved;

map<int, pii> lookup;

inline void print() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%d%c", board[i][j], j == SIZE - 1 ? '\n' : ' ');
        }
    }
}

void dfs(int x, int y) {
    if (solved || row_sum[x] > SUM || col_sum[y] > SUM) return;

    if (board[x][y] == 1) {
        solved = true;
        print();
        return;
    }

    int next = board[x][y] - 1;
    if (lookup.find(next) != end(lookup)) {
        pii pos = lookup[next];
        int deltx = abs(pos.first - x);
        int delty = abs(pos.second - y);

        if (deltx == delty || deltx < 1 || deltx > 2 || delty < 1 || delty > 2)
            return;

        dfs(pos.first, pos.second);
    } else {
        for (int d = 0; d < 8; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (0 <= nx && nx < SIZE && 0 <= ny && ny < SIZE && board[nx][ny] == 0) {
                board[nx][ny] = next;
                row_sum[nx] += next;
                col_sum[ny] += next;

                dfs(nx, ny);

                board[nx][ny] = 0;
                row_sum[nx] -= next;
                col_sum[ny] -= next;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == -1) {
                board[i][j] = 0;
            } else {
                lookup[board[i][j]] = {i, j};
            }

            row_sum[i] += board[i][j];
            col_sum[j] += board[i][j];
        }
    }

    solved = false;
    if (lookup.find(64) != end(lookup)) {
        pii start = lookup[64];
        dfs(start.first, start.second);
    } else {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 64;
                    row_sum[i] += 64;
                    col_sum[j] += 64;

                    dfs(i, j);

                    board[i][j] = 0;
                    row_sum[i] -= 64;
                    col_sum[j] -= 64;
                }
            }
        }
    }
    
    return 0;
}
