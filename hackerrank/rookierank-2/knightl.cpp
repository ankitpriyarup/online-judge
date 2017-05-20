#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 30;
int n;
int ans[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = {1, -1, 1, -1};
int dy[] = {1, 1, -1, -1};

inline bool in_bounds(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < n;
}

int bfs(int a, int b) {
    // return the number of moves to go from (0, 0) to (n - 1, n - 1)
    queue<pair<int, int> > q;
    int level = 0;
    q.push(make_pair(0, 0));
    memset(visited, 0, sizeof(visited));
    visited[0][0] = true;
    
    while (!q.empty()) {
        int level_size = q.size();
        
        while (level_size-- > 0) {
            pair<int, int> pos = q.front();
            q.pop();
            
            if (pos.first == n - 1 and pos.second == n - 1) {
                return level;
            }
            
            for (int d = 0; d < 4; ++d) {
                int nx = pos.first + a * dx[d];
                int ny = pos.second + b * dy[d];
                if (in_bounds(nx, ny) and !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
            
            for (int d = 0; d < 4; ++d) {
                int nx = pos.first + b * dx[d];
                int ny = pos.second + a * dy[d];
                if (in_bounds(nx, ny) and !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        
        ++level;
    }
    
    return -1;
}

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ans[i][j] = bfs(i, j);
            ans[j][i] = ans[i][j];
        }
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
    
    return 0;
}
