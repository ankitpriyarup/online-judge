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

constexpr int MAXN = 7003;
constexpr int MAXM = 300005;
constexpr int MAXW = 100005;
int n, m;

struct edge {
    int u, v, i;
};

namespace uf {
    int par[MAXN];
    void init() {
        for (int i = 0; i <= n; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        return par[x] = (x == par[x] ? x : find(par[x]));
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return false;

        par[xr] = yr;
        return true;
    }
}

bool ans[MAXM];
vector<edge> edges[MAXW];

int main() {
    scanf("%d %d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[w].push_back({u, v, i});
    }

    uf::init();
    for (int w = 0; w < MAXW; ++w) {
        for (int k = 0; k < edges[w].size(); ++k) {
            ans[edges[w][k].i] = !uf::same(edges[w][k].u, edges[w][k].v);
        }

        for (int k = 0; k < edges[w].size(); ++k) {
            uf::merge(edges[w][k].u, edges[w][k].v);
        }
    }

    for (int i = 0; i < m; ++i) {
        printf("%s\n", ans[i] ? "TAK" : "NIE");
    }

    return 0;
}
