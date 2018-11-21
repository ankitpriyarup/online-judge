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
using query = tuple<int, int, int, int>;

constexpr ll INF = 1e18;
constexpr int MAXN = 102;
constexpr int MAXQ = 100005;
int n;
ll adj[MAXN][MAXN];
ll cur[MAXN][MAXN];
ll temp[MAXN][MAXN];

int q;
query queries[MAXQ];

ll ans[MAXQ];

void read() {
    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %lld", &adj[i][j]);
            if (!adj[i][j])
                adj[i][j] = INF;
        }

        adj[i][i] = 0;
    }

    scanf(" %d", &q);
    int u, v, d;
    for (int i = 0; i < q; ++i) {
        scanf(" %d %d %d", &u, &v, &d);
        --u; --v;
        queries[i] = {d, u, v, i};
    }
}

void fw() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

void step() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i][j] = cur[i][j];

            for (int k = 0; k < n; ++k) {
                temp[i][j] = min(temp[i][j], max(cur[i][k], adj[k][j]));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cur[i][j] = temp[i][j];
        }
    }
}

void dump_cur() {
    return;
    printf("---------------------");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%lld ", cur[i][j]);
        }

        printf("\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // read in matrix
    // floyd warshall
    // save every power of 2 of the weird matrix mult
    // m[i][j] = min_k max(m[i][k], m[k][j])
    //
    // read in all queries
    // sort by d
    // for every d, increment
    // should be O(n^4 + qlogq)
    // hopefully fast enough?
    read();
    fw();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cur[i][j] = adj[i][j];
        }
    }

    sort(queries, queries + q);
    int cur_d = 1;

    dump_cur();

    int d, u, v, idx;
    for (int i = 0; i < q; ++i) {
        tie(d, u, v, idx) = queries[i];
        while (cur_d < d) {
            step();
            ++cur_d;

            // printf("Cur d now %d\n", cur_d);
            dump_cur();
        }

        ans[idx] = cur[u][v];
        if (ans[idx] == INF) {
            ans[idx] = 0;
        }
    }

    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
