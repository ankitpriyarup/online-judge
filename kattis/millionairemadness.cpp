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
ll a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool works(ll v) {
    queue<pii> q;
    q.push({0, 0});
    int x, y;
    memset(vis, 0, sizeof(vis));
    vis[0][0] = true;
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx and nx < n and 0 <= ny and ny < m and !vis[nx][ny] and a[nx][ny] - a[x][y] <= v) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return vis[n - 1][m - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%lld", &a[i][j]);
        }
    }

    if (works(0)) {
        printf("%d\n", 0);
        return 0;
    }

    ll lo = 0;
    ll hi = 1e16;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2LL;
        if (works(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%lld\n", hi);

    return 0;
}
