#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>

using namespace std;

int N, M;
char board[2002][2002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct free_point {
    int x, y, d;
    free_point(int x, int y, int d): x(x), y(y), d(d) {}
};

bool in_bounds(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}
int count_around(int x, int y) {
    int ans = 0;
    int ret = -1;
    if (in_bounds(x - 1, y) && board[x - 1][y] == '.') {
        ans++;
        ret = 2;
    }

    if (in_bounds(x, y - 1) && board[x][y - 1] == '.') {
        ans++;
        ret = 3;
    }

    if (in_bounds(x + 1, y) && board[x + 1][y] == '.') {
        ans++;
        ret = 0;
    }

    if (in_bounds(x, y + 1) && board[x][y + 1] == '.') {
        ans++;
        ret = 1;
    }

    return ans == 1 ? ret : -1;
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int count_star = 0;
    queue<free_point> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // see if you can fill the board uniquely
            if (board[i][j] == '.') {
                count_star++;
                int ca = count_around(i, j);
                if (ca != -1) {
                    q.push(free_point(i, j, ca));
                }
            }
        }
    }

    while (!q.empty()) {
        free_point fp = q.front();
        q.pop();

        if (board[fp.x][fp.y] != '.' || board[fp.x + dx[fp.d]][fp.y + dy[fp.d]] != '.') {
            continue;
        }
        // fill in this point
        count_star -= 2;
        switch(fp.d) {
            case 0:
                board[fp.x][fp.y] = '^';
                board[fp.x + dx[fp.d]][fp.y + dy[fp.d]] = 'v';
                break;
            case 1:
                board[fp.x][fp.y] = '<';
                board[fp.x + dx[fp.d]][fp.y + dy[fp.d]] = '>';
                break;
            case 2:
                board[fp.x][fp.y] = 'v';
                board[fp.x + dx[fp.d]][fp.y + dy[fp.d]] = '^';
                break;
            case 3:
                board[fp.x][fp.y] = '>';
                board[fp.x + dx[fp.d]][fp.y + dy[fp.d]] = '<';
                break;
        }

        // check the area around the second point for new candidates
        for (int d = 0; d < 4; d++) {
            int nx = fp.x + dx[fp.d] + dx[d];
            int ny = fp.y + dy[fp.d] + dy[d];
            if (board[nx][ny] == '.') {
                int ca = count_around(nx, ny);
                if (ca != -1) {
                    q.push(free_point(nx, ny, ca));
                }
            }
        }
    }

    if (count_star > 0) {
        cout << "Not unique" << '\n';
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}
