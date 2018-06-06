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

constexpr int MAXN = 555;
int n, m;
int a[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf(" %d", &a[i][j]);
        }
    }

    int sx, sy;
    scanf(" %d %d", &sx, &sy);
    priority_queue<pair<int, pii>> pq;
    pq.push({-a[sx][sy], {sx, sy}});

    ll ans = 0LL;
    int dist;
    pii pos;
    int x, y;
    while (!pq.empty()) {
        tie(dist, pos) = pq.top();
        pq.pop();
        tie(x, y) = pos;

        if (vis[x][y]) continue;

        vis[x][y] = true;
        int h = min(-a[x][y], dist);
        ans += h;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (!dx and !dy) continue;
                int nx = x + dx;
                int ny = y + dy;
                if (vis[nx][ny] or a[nx][ny] >= 0)
                    continue;
                pq.push({min(-a[nx][ny], h), {nx, ny}});
            }
        }
    }

    printf("%lld\n", ans);
    
    return 0;
}
