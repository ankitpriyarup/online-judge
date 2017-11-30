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

constexpr int MAXN = 502;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, -1, 0, 1};
int n, m;
int a[MAXN][MAXN];

namespace uf {
    int par[MAXN * MAXN];
    int sz[MAXN * MAXN];
    void init(int cap) {
        for (int i = 0; i < cap; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        return par[x] = (x == par[x] ? x : find(par[x]));
    }

    int find(int x, int y) {
        return find(x * m + y);
    }

    void merge(int x, int y) {
        int xr = uf::find(x);
        int yr = uf::find(y);
        if (xr == yr) return;

        // printf("Merging %d and %d\n", x, y);

        sz[yr] += sz[xr];
        sz[xr] = 0;
        par[xr] = yr;
    }

    void merge(int a, int b, int c, int d) {
        merge(m * a + b, m * c + d);
    }
}

bool outgoing[MAXN * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    uf::init(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if (0 <= nx and nx < n and 0 <= ny and ny < m and a[i][j] == a[nx][ny]) {
                    uf::merge(i, j, nx, ny);
                }
            }
        }
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if (0 <= nx and nx < n and 0 <= ny and ny < m and a[i][j] > a[nx][ny]) {
                    outgoing[uf::find(i, j)] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
        if (uf::find(i) == i and !outgoing[i]) {
            // printf("Collecting at %d\n", i);
            ans += uf::sz[i];
        }
    }

    printf("%d\n", ans);
       
    return 0;
}
