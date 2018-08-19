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

constexpr int MAXN = 1505;
constexpr int INF = 1e9 + 7;
int n;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
        scanf(" %s", grid[i]);
        for (int j = 0; j < n; ++j) {
            dist[i][j] = INF;

            if (grid[i][j] == '3') {
                dist[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    int x, y;
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx and nx < n and 0 <= ny and ny < n) {
                if (1 + dist[x][y] < dist[nx][ny]) {
                    dist[nx][ny] = 1 + dist[x][y];
                    q.emplace(nx, ny);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1')
                ans = max(ans, dist[i][j]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
