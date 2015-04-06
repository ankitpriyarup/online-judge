#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, size;
int grid[12][12];
bool visited[12][12];
int dx[] = {1, 0, -1, -1, -1, 0, 1, 1};
int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M || visited[x][y] || grid[x][y] != 1) return;

    visited[x][y] = true;
    size++;
    for (int d = 0; d < 8; d++) {
        dfs(x + dx[d], y + dy[d]);
    }

    return;
}

int main() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            size = 0;
            dfs(i, j);
            answer = max(size, answer);
        }
    }

    cout << answer << '\n';

    return 0;
}
