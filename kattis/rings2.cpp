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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n + 2, string(m + 2, '.'));
    vector<vector<int>> dist(n + 2, vector<int>(m + 2, -1));
    queue<pii> q;
    string row;
    for (int i = 1; i <= n; ++i) {
        cin >> row;
        for (int j = 1; j <= m; ++j) {
            grid[i][j] = row[j - 1];
        }
    }
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            if (grid[i][j] == '.') {
                dist[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    int max_dist = 0;
    int x, y;
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (0 <= nx and nx < n + 2 and 0 <= ny and ny < m + 2 and dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                max_dist = max(max_dist, dist[nx][ny]);
                q.emplace(nx, ny);
            }
        }
    }

    int len = max_dist < 10 ? 2 : 3;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int buf = len;
            if (dist[i][j] > 0)
                --buf;
            if (dist[i][j] >= 10)
                --buf;

            for (int k = 0; k < buf; ++k) {
                cout << ".";
            }
            if (dist[i][j])
                cout << dist[i][j];
        }
        cout << '\n';
    }

    return 0;
}
