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
constexpr ld INF = 1e18;
constexpr ld EPS = 1e-9;
int n, m;
ld rad;

ld dist[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %Lf", &m, &n, &rad);
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            dist[i][j] = INF;
        }
    }

    int sx, sy, gx, gy;
    scanf("%d %d %d %d", &sx, &sy, &gx, &gy);
    dist[sx][sy] = 0.0L;

    priority_queue<pair<ld, pii>, vector<pair<ld, pii> >, greater<pair<ld, pii> > > pq;
    pq.push({0.0L, {sx, sy}});
    int x, y;

    while (!pq.empty()) {
        pair<ld, pii> cur = pq.top();
        pq.pop();

        tie(x, y) = cur.second;
        if (cur.first > dist[x][y] + EPS)
            continue;

        // printf("Dist to %d %d is %.2Lf\n", x, y, cur.first);

        ld y_dist = cur.first + rad / n;
        ld x_dist = cur.first + M_PI * y * rad / n / m;

        for (int yp = y - 1; yp <= y + 1; yp += 2) {
            if (0 <= yp and yp <= n) {
                if (y_dist < dist[x][yp]) {
                    dist[x][yp] = y_dist;
                    pq.push({y_dist, {x, yp}});
                }
            }
        }

        for (int xp = x - 1; xp <= x + 1; xp += 2) {
            if (0 <= xp and xp <= m) {
                if (x_dist < dist[xp][y]) {
                    dist[xp][y] = x_dist;
                    pq.push({x_dist, {xp, y}});
                }
            }
        }
    }

    printf("%.17Lf\n", dist[gx][gy]);

    return 0;
}
