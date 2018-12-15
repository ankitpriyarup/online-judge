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

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int n, m, q;
    scanf(" %d %d %d", &n, &m, &q);
    int x, y;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pii> qq;
    while (q-- > 0) {
        scanf(" %d %d", &x, &y);
        --x; --y;
        if (vis[x][y] == 0) {
            qq.emplace(x, y);
            vis[x][y] = 1;
        }
    }

    int day = 0;
    while (!qq.empty()) {
        ++day;
        int sz = qq.size();
        while (sz-- > 0) {
            tie(x, y) = qq.front();
            qq.pop();

            // printf("--- (y, y) = (%d, %d). vis = %d, day = %d\n", x, y, vis[x][y], day);

            assert(vis[x][y] == day);
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (0 <= nx and nx < n and 0 <= ny and ny < m and vis[nx][ny] == 0) {
                    vis[nx][ny] = day + 1;
                    qq.emplace(nx, ny);
                }
            }
        }
    }

    printf("%d\n", day);

    return 0;
}
