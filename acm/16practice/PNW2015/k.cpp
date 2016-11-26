#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n;
char grid[30][30];

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

vector<pair<int, int> > blacks;
int white_count = 0;

void format(pair<int, int> pos) {
    int row = n - pos.first;
    char col = 'a' + pos.second;

    cout << col << row << '\n';
}

bool in_bounds(int x, int y) {
    return 0 <= x and x < n
       and 0 <= y and y < n;
}

bool can_solve(int x, int y) {
    if (white_count == 0) {
        return true;
    }

    bool works = false;
    for (int d = 0; !works and d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        int nnx = nx + dx[d];
        int nny = ny + dy[d];
        if (in_bounds(nx, ny) 
        and in_bounds(nnx, nny) 
        and grid[nx][ny] == 'W' 
        and grid[nnx][nny] == '_') {

            // Try this jump
            grid[x][y] = '_';
            grid[nx][ny] = '_';
            grid[nnx][nny] = 'B';
            --white_count;

            works |= can_solve(nnx, nny);

            ++white_count;
            grid[nnx][nny] = '_';
            grid[nx][ny] = 'W';
            grid[x][y] = 'B';
        }
    }

    return works;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'W') {
                white_count++;
            } else if (grid[i][j] == 'B') {
                blacks.push_back(make_pair(i, j));
            }
        }
    }

    vector<pair<int, int> > sol;
    for (pair<int, int> black : blacks) {
        if (sol.size() > 1) {
            break;
        }

        if (can_solve(black.first, black.second)) {
            sol.push_back(black);
        }
    }

    switch(sol.size()) {
        case 0:
            cout << "None\n";
            break;
        case 1:
            format(sol[0]);
            break;
        case 2:
            cout << "Multiple\n";
            break;
    }
    return 0;
}
