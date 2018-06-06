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

constexpr int MAXN = 1000006;
constexpr int LOGN = 22;
int n, k;
vector<int> tree[MAXN];
int st[LOGN][MAXN];
int depth[MAXN];
int take[MAXN];

void dfs(int u, int p = -1) {
    for (int v : tree[u]) {
        if (v == p) continue;
        st[0][v] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void gen_st() {
    for (int j = 0; j + 1 < LOGN; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (st[j][i] != -1) {
                st[j + 1][i] = st[j][st[j][i]];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &k);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf(" %d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(st, -1, sizeof(st));
    depth[n] = 0;
    dfs(n);
    int safe_rem = n - k - 1;
    take[n] = true;
    gen_st();

    for (int u = n - 1; safe_rem > 0 and u >= 1; --u) {
        if (take[u]) continue;

        int v = u;
        for (int j = LOGN - 1; j >= 0; --j) {
            // printf("2^%d parent of %d is %d\n", j, v, st[j][v]);
            if (st[j][v] != -1 and !take[st[j][v]]) {
                v = st[j][v];
            }
        }

        int taken = depth[u] - depth[v] + 1;
        // printf("Taking all from %d to %d requires %d\n", u, v, taken);
        if (taken <= safe_rem) {
            safe_rem -= taken;
            int delta = 0;
            v = u;
            assert(!take[v]);
            while (!take[v]) {
                take[v] = true;
                ++delta;
                v = st[0][v];
                assert(v != -1);
            }
            assert(delta == taken);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!take[i]) printf("%d ", i);
    }
    printf("\n");

    return 0;
}
