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

constexpr int MAXN = 20004;
constexpr int MAXM = 30004;
int uf[MAXN];
int n, m;

struct edge {
    int u, v, w;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
} edges[MAXM];

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

bool merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return false;

    uf[xr] = yr;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 and m == 0)
            break;

        for (int u = 0; u < n; ++u)
            uf[u] = u;

        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        sort(edges, edges + m);
        int cc = n;
        int score = 0;
        vector<pii> res;
        for (int i = 0; i < m; ++i) {
            if (merge(edges[i].u, edges[i].v)) {
                --cc;
                score += edges[i].w;
                res.push_back({min(edges[i].u, edges[i].v), max(edges[i].u, edges[i].v)});
            }
        }

        if (cc != 1)
            printf("Impossible\n");
        else {
            printf("%d\n", score);
            sort(begin(res), end(res));
            for (const auto& p : res) {
                printf("%d %d\n", p.first, p.second);
            }
        }
    }

    return 0;
}
