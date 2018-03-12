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

constexpr int MAXN = 55;
int n, m;
int deg[MAXN], uf[MAXN];

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

int unite(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return false;

    uf[xr] = yr;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &n, &m);
    int comp = n;
    for (int i = 1; i <= n; ++i)
        uf[i] = i;

    memset(deg, 0, sizeof(deg));

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        ++deg[u]; ++deg[v];
        if (deg[u] > 2 or deg[v] > 2) {
            printf("NO\n");
            return 0;
        }

        comp -= unite(u, v);
    }

    vector<pii> edges;
    while (true) {
        bool found = false;
        for (int i = 1; !found and i <= n; ++i) {
            for (int j = i + 1; !found and j <= n; ++j) {
                if (deg[i] < 2 and deg[j] < 2 and find(i) != find(j)) {
                    // printf("MAKING %d %d\n", i, j);
                    ++deg[i];
                    ++deg[j];
                    comp -= unite(i, j);
                    edges.emplace_back(i, j);
                    found = true;
                    break;
                }
            }
        }

        if (!found) break;
    }

    if (comp != 1) {
        printf("NO\n");
        return 0;
    }

    if (n == 1) {
        if (deg[1] < 2) {
            edges.emplace_back(1, 1);
            deg[1] = 2;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (deg[i] < 2 and deg[j] < 2) {
                    ++deg[i];
                    ++deg[j];
                    edges.emplace_back(i, j);
                    comp -= unite(i, j);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (comp != 1 or deg[i] != 2) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    printf("%d\n", static_cast<int>(edges.size()));
    for (auto& p : edges) {
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}
