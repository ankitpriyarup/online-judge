#include <iostream>
#include <iomanip>
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

constexpr int MAXN = 505;
int n, m;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool in_bounds(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    queue<pii> q;
    q.push({0, 0});
    memset(dist, -1, sizeof(dist));
    dist[0][0] = 0;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        int jump = grid[x][y] - '0';

        for (int d = 0; d < 4; ++d) {
            int nx = x + jump * dx[d];
            int ny = y + jump * dy[d];
            if (in_bounds(nx, ny) and dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    printf("%d\n", dist[n - 1][m - 1]);
    
    return 0;
}
