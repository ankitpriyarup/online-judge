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

constexpr int MAXN = 200005;
constexpr int INF = 1e9;

int n;
int a[MAXN];
int b[MAXN];

// Dynamic split-merge segment trees
// Taken from 

struct node {
    int l, r;
};

node nodes[100 * MAXN];
int sz = 1;

int trees[101];

// returns roots of two trees. The left tree contains values < v and the right
// tree contains values >= v
pair<int, int> split(int node, int l, int r, int v) {
    if (node == 0)
        return {0, 0};

    if (l == r) {
        if (l < v)
            return {node, 0};
        else
            return {0, node};
    }

    int mid = (l + r) >> 1;
    int copy = sz++;
    if (v <= mid) {
        int le, geq;
        tie(le, geq) = split(nodes[node].l, l, mid, v);
        nodes[copy].l = le;
        nodes[node].l = geq;

        return {copy, node};
    } else {
        int le, geq;
        tie(le, geq) = split(nodes[node].r, mid + 1, r, v);
        nodes[node].r = le;
        nodes[copy].r = geq;

        return {node, copy};
    }
}

int create(int l, int r, int v) {
    int cur = sz++;
    if (l == r) {
        return cur;
    }

    int mid = (l + r) >> 1;
    if (v <= mid) {
        nodes[cur].l = create(l, mid, v);
    } else {
        nodes[cur].r = create(mid + 1, r, v);
    }

    return cur;
}

int merge(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    nodes[a].l = merge(nodes[a].l, nodes[b].l);
    nodes[a].r = merge(nodes[a].r, nodes[b].r);

    return a;
}

template <typename F>
void dfs(int node, int l, int r, F f) {
    if (node == 0)
        return;

    if (l == r) {
        f(l);
    } else {
        int mid = (l + r) >> 1;
        dfs(nodes[node].l, l, mid, f);
        dfs(nodes[node].r, mid + 1, r, f);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        trees[a[i]] = merge(trees[a[i]], create(0, n - 1, i));
    }

    /*
    for (int x = 1; x < 100; ++x) {
        dfs(trees[x], 0, n - 1, [&](const int& i) {
            printf("index %d has value %d\n", i, x);
        });
    }
    */

    int q;
    scanf("%d", &q);
    int l, r, x, y;
    int left, center, right;
    while (q-- > 0) {
        scanf("%d %d %d %d", &l, &r, &x, &y);

        tie(left, center) = split(trees[x], 0, n - 1, l - 1);
        tie(center, right) = split(center, 0, n - 1, r);
        trees[x] = merge(left, right);
        trees[y] = merge(trees[y], center);
    }

    for (int x = 1; x <= 100; ++x) {
        dfs(trees[x], 0, n - 1, [&](const int& i) {
            b[i] = x;
        });
    }

    for (int i = 0; i < n; ++i) {
        printf("%d%c", b[i], " \n"[i == n - 1]);
    }

    return 0;
}
