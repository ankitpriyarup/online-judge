#include <iostream>
#include <set>

using namespace std;

int K, N, M;
char grid[15][15][15];

struct pos {
    int x, y, z;
    pos(int x, int y, int z): x(x), y(y), z(z) {}
};

bool operator<(const pos &a, const pos &b) {
    if (a.x == b.x && a.y == b.y) {
        return a.z < b.z;
    } else if (a.x == b.x) {
        return a.y < b.y;
    } else {
        return a.x < b.x;
    }
}

int dx[] = {1, 0, 0, -1, 0, 0};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {0, 0, 1, 0, 0, -1};
int size = 0;
set<pos> visited;

void dfs(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= K || y >= N || z >= M || grid[x][y][z] == '#') {
        return;
    }

    pos cur = pos(x, y, z);
    if (visited.find(cur) == visited.end()) {
        //cout << x << " " << y << " " << z << '\n';
        visited.insert(cur);
        size += 1;
        for (int d = 0; d < 6; ++d) {
            dfs(x + dx[d], y + dy[d], z + dz[d]);
        }
    }
}

int main() {
    cin >> K >> N >> M;
    string temp;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    /*
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cout << grid[i][j][k];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    */

    dfs(0, x - 1, y - 1);    

    cout << size << '\n';
    return 0;
}
