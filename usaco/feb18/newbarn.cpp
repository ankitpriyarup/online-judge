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
using vi = vector<int>;

constexpr int MAXN = 200005;
constexpr int LOGN = 19;

int n = 0;
int depth[MAXN];
int st[LOGN][MAXN];
int uf[MAXN];
pii diams[MAXN];

int lca(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);

    if (depth[v] > depth[u]) {
        int delta = depth[v] - depth[u];
        for (int j = LOGN - 1; j >= 0; --j) {
            if (delta & (1 << j))
                v = st[j][v];
        }
    }

    if (u == v)
        return u;

    for (int j = LOGN - 1; j >= 0; --j) {
        if (st[j][u] != st[j][v]) {
            u = st[j][u];
            v = st[j][v];
        }
    }

    return st[0][u];
}

int dist(int u, int v) {
    int l = lca(u, v);
    int res = depth[u] + depth[v] - 2 * depth[l];
    assert(res >= 0);

    return res;
}

int dist(int u) {
    int a, b;
    tie(a, b) = diams[uf[u]];

    return max(dist(u, a), dist(u, b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("newbarn.in", "r", stdin);
    freopen("newbarn.out", "w", stdout);

    int q;
    scanf(" %d", &q);
    n = 0;

    memset(st, -1, sizeof(st));
    char op;
    int par;
    for (int i = 0; i < q; ++i) {
        scanf(" %c %d", &op, &par);
        --par;
        if (op == 'B') {
            if (par >= 0) {
                st[0][n] = par;
                for (int j = 0; j + 1 < LOGN; ++j) {
                    if (st[j][n] != -1)
                        st[j + 1][n] = st[j][st[j][n]];
                }

                uf[n] = uf[par];
                depth[n] = depth[par] + 1;
                int a = diams[uf[n]].first;
                int b = diams[uf[n]].second;

                if (dist(n, a) > dist(a, b)) {
                    diams[uf[n]].second = n;
                } else if (dist(n, b) > dist(a, b)) {
                    diams[uf[n]].first = n;
                }
            } else {
				uf[n] = n;
                diams[n] = make_pair(n, n);
                depth[n] = 0;
            }

            ++n;
        } else {
            printf("%d\n", dist(par));
        }
    }

    return 0;
}
