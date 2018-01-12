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

constexpr int MAXN = 80;
constexpr int INF = 1e9 + 7;
int n, m;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
pii previous[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 and m == 0)
            break;

        for (int i = 0; i < n; ++i) {
            scanf("%s", grid[i]);
            for (int j = 0; j < m; ++j)
                dist[i][j] = INF;
        }

        priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > pq;
        for (int j = 0; j < m; ++j) {
            dist[0][j] = grid[0][j] - '0';
            pq.push({dist[0][j], {0, j}});
        }

        int x, y;
        while (!pq.empty()) {
            int cur_dist = pq.top().first;
            tie(x, y) = pq.top().second;
            pq.pop();

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 and dy == 0)
                        continue;

                    int nx = x + dx;
                    int ny = y + dy;
                    if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                        int new_dist = cur_dist + grid[nx][ny] - '0';
                        if (new_dist < dist[nx][ny]) {
                            dist[nx][ny] = new_dist;
                            previous[nx][ny] = {x, y};
                            pq.push({dist[nx][ny], {nx, ny}});
                        }
                    }
                }
            }
        }

        int start = 0;
        for (int j = 0; j < m; ++j) {
            if (dist[n - 1][j] < dist[n - 1][start])
                start = j;
        }

        pii cur = {n - 1, start};
        while (cur.first != 0) {
            grid[cur.first][cur.second] = ' ';
            cur = previous[cur.first][cur.second];
        }

        grid[cur.first][cur.second] = ' ';
        for (int i = 0; i < n; ++i)
            printf("%s\n", grid[i]);
        printf("\n");
    }

    return 0;
}
