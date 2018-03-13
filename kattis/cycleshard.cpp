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

constexpr int MAXN = 303;
constexpr int MAXK = 16;
constexpr int MOD = 9901;
constexpr int INV2 = (MOD + 1) / 2;

inline int sum(const int& a, const int& b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;
    return c;
}

inline int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}

int n, k;
vector<pii> edges;
int fact[MAXN];
int uf[MAXN], sz[MAXN], szdeg[MAXN];

void genfact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = prod(fact[i - 1], i);
    }
}

int find(int x) {
    return uf[x] = x == uf[x] ? x : find(uf[x]);
}

int merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) 
        return false;

    uf[xr] = yr;
    sz[yr] += sz[xr];
    szdeg[yr] += szdeg[xr];
    sz[xr] = 0;
    szdeg[xr] = 0;
    return true;
}

int count_paths(int mask) {
    vector<int> deg(n, 0);
    int comp = n;
    for (int i = 0; i < k; ++i) {
        if (mask & (1 << i)) {
            // printf("Using edge (%d, %d)\n", edges[i].first, edges[i].second);
            if (++deg[edges[i].first] > 2) {
                return 0;
            }

            if (++deg[edges[i].second] > 2) {
                // printf("Too many %d\n", edges[i].second);
                return 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        uf[i] = i;
        sz[i] = 1;
        szdeg[i] = deg[i];
    }

    for (int i = 0; i < k; ++i) {
        if (mask & (1 << i)) {
            comp -= merge(edges[i].first, edges[i].second);
        }
    }

    int ans = fact[comp - 1];
    for (int i = 0; i < n; ++i) {
        if (sz[i] > 1) 
            ans = prod(2, ans);

        if (szdeg[i] == 2 * sz[i] and sz[i] >= 1 and sz[i] < n) 
            return 0;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    int tc = 1;
    genfact();
    while (T-- > 0) {
        scanf("%d %d", &n, &k);
        int u, v;
        edges.clear();
        for (int i = 0; i < k; ++i) {
            scanf("%d %d", &u, &v);
            --u; --v;
            edges.emplace_back(u, v);
        }

        int ans = 0;
        for (int mask = 0; mask < (1 << k); ++mask) {
            int pc = __builtin_popcount(mask);
            int score = count_paths(mask);
            // printf("mask: %x, score: %d\n", mask, score);
            if (pc & 1) {
                ans = sum(ans, MOD - score);
            } else {
                ans = sum(ans, score);
            }
        }

        ans = prod(ans, INV2);
        printf("Case #%d: %d\n", tc++, ans);
    }

    return 0;
}
