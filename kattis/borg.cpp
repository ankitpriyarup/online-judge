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

constexpr int MAXN = 102;
string grid[MAXN];
int dist[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while (T-- > 0) {
        int n, m;
        cin >> m >> n;
        getline(cin, grid[0]);
        int sx, sy;
        for (int i = 0; i < n; ++i) {
            getline(cin, grid[i]);
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }

        memset(dist, -1, sizeof(dist));
        priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > pq;
        pq.push({0, {sx, sy}});
        dist[sx][sy] = 0;

        int ans = 0;
        while (!pq.empty()) {
            int cur_dist = pq.top().first;
            pii pos = pq.top().second;
            pq.pop();


            if (cur_dist != dist[pos.first][pos.second]) {
                continue;
            }

            if (grid[pos.first][pos.second] == 'A') {
                ans += cur_dist;
                cur_dist = 0;
                dist[pos.first][pos.second] = 0;
            }

            for (int d = 0; d < 4; ++d) {
                int nx = pos.first + dx[d];
                int ny = pos.second + dy[d];

                if (0 <= nx and nx < MAXN and 0 <= ny and ny < MAXN and grid[nx][ny] != '#') {
                    if (dist[nx][ny] == -1 or cur_dist + 1 < dist[nx][ny]) {
                        dist[nx][ny] = 1 + cur_dist;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}
