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
using edge = tuple<int, int, int>;

constexpr int MAXN = 200005;
int n;
edge edges[MAXN];
map<int, int> raw[MAXN];
map<int, int>* dp[MAXN];
int uf[MAXN];
ll ans[MAXN];

void merge_maps(map<int, int>* small, map<int, int>* large, int w) {
    /*
    printf("Small map: \n");
    for (auto p : *small) {
        printf("%d %d\n", p.first, p.second);
    }
    printf("Large map: \n");
    for (auto p : *large) {
        printf("%d %d\n", p.first, p.second);
    }
    printf("\n");
    */

    for (auto p : *small) {
        int v1 = p.second;
        int v2 = (*large)[p.first];
        if ((v1 > 0 and v2 < 0) or (v1 < 0 and v2 > 0)) {
            int coeff = min(abs(v1), abs(v2));
            ans[p.first] += 1LL * coeff * w;
        }

        (*large)[p.first] += v1;
    }
}

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

int merge(int x, int y, int w) {
    int xr = find(x);
    int yr = find(y);

    if (xr == yr) {
        assert(0);
        return 0;
    }

    if (dp[xr]->size() < dp[yr]->size()) {
        uf[xr] = yr;
        merge_maps(dp[xr], dp[yr], w);
    } else {
        uf[yr] = xr;
        merge_maps(dp[yr], dp[xr], w);
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    int w, u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf(" %d %d %d", &u, &v, &w);
        --u; --v;
        edges[i] = {w, u, v};
    }

    sort(edges, edges + n - 1);

    for (int i = 0; i < n; ++i) {
        dp[i] = &raw[i];
    }

    int q, m, x;
    scanf(" %d", &q);
    for (int i = 0; i < q; ++i) {
        scanf(" %d", &m);
        for (int j = 0; j < m; ++j) {
            scanf(" %d %d", &x, &v);
            --x;
            (*(dp[x]))[i] += v;
        }
    }

    iota(uf, uf + n, 0);
    for (int ee = 0; ee < n - 1; ++ee) {
        tie(w, u, v) = edges[ee];
        // printf("Processing edge %d %d %d\n", u + 1, v + 1, w);
        merge(u, v, w);
    }

    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
