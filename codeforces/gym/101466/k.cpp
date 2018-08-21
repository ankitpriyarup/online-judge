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
#include <array>
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

// lol
constexpr int NP = 6;
constexpr int primes[NP] = {2, 3, 5, 7, 11, 13};
using cell = vector<int>;
constexpr int MOD = 1e9 + 7;

int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD) {
        c -= MOD;
    }

    return c;
}

int prod(int a, int b) {
    return 1LL * a * b % MOD;
}

int modpow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp) {
            res = prod(res, cur);
        }

        cur = prod(cur, cur);
    }

    return res;
}

constexpr int MAXN = 100005;
int n;
vector<int> tree[MAXN];
int par[MAXN];
int init_val[MAXN];

void read_tree() {
    int u, v;
    memset(par, -1, sizeof(par));
    for (int i = 0; i < n - 1; ++i) {
        scanf(" %d %d", &u, &v);
        tree[u].push_back(v);
        par[v] = u;
    }
}

int timer = 0;
int tin[MAXN], rtin[MAXN], tout[MAXN];
void dfs(int u) {
    tin[u] = timer++;
    rtin[tin[u]] = u;
    for (int v : tree[u]) {
        dfs(v);
    }
    tout[u] = timer;
}

cell seg_tree[4 * MAXN];

cell merge(const cell& a, const cell& b) {
    cell c(NP);
    for (int i = 0; i < NP; ++i)
        c[i] = a[i] + b[i];
    return c;
}

cell create_cell(int x) {
    cell c(NP, 0);
    for (int i = 0; i < NP; ++i) {
        while (x % primes[i] == 0) {
            x /= primes[i];
            ++c[i];
        }
    }

    return c;
}

void pull(int node) {
    seg_tree[node] = merge(seg_tree[2 * node], seg_tree[2 * node + 1]);
}

cell query(int node, int l, int r, int ql, int qr) {
    if (qr < l or r < ql) {
        cell c(NP, 0);
        return c;
    }

    if (ql <= l and r <= qr) {
        return seg_tree[node];
    }

    int mid = (l + r) >> 1;
    return merge(query(2 * node, l, mid, ql, qr),
                 query(2 * node + 1, mid + 1, r, ql, qr));
}

void update(int node, int l, int r, int idx, int x) {
    if (idx < l or idx > r) return;
    if (idx == l and idx == r) {
        seg_tree[node] = merge(seg_tree[node], create_cell(x));
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * node, l, mid, idx, x);
    update(2 * node + 1, mid + 1, r, idx, x);
    pull(node);
}

pii simplify(const cell& counts) {
    int val = 1;
    int divs = 1;
    for (int i = 0; i < NP; ++i) {
        val = prod(val, modpow(primes[i], counts[i]));
        divs = prod(divs, counts[i] + 1);
    }

    return {val, divs};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    read_tree();
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &init_val[i]);
    }

    int root = 0;
    while (par[root] != -1)
        root = par[root];
    dfs(root);

    for (int i = 0; i < 4 * MAXN; ++i) {
        seg_tree[i] = cell(NP, 0);
    }

    for (int u = 0; u < n; ++u) {
        update(1, 0, n - 1, tin[u], init_val[u]);
    }

    int q;
    scanf(" %d", &q);
    int u, x;
    char buf[15];
    while (q-- > 0) {
        scanf("%s %d", buf, &u);
        if (buf[0] == 'R') {
            cell res = query(1, 0, n - 1, tin[u], tout[u] - 1);
            auto output = simplify(res);
            printf("%d %d\n", output.first, output.second);
        } else {
            scanf(" %d", &x);
            update(1, 0, n - 1, tin[u], x);
        }
    }

    return 0;
}
