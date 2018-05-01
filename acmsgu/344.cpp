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

constexpr int MAXN = 1003;
int n, m;
int neighbors[MAXN][MAXN];
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    queue<pii> q;
    for (int i = 0; i < n; ++i) {
        scanf(" %s", grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'X') {
                q.emplace(i, j);
                vis[i][j] = true;
            }
        }
    }

    int x, y;
    int ans = 0;
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        ++ans;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                ++neighbors[nx][ny];
                if (!vis[nx][ny] and neighbors[nx][ny] >= 2) {
                    vis[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
