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
int tree[2][4 * MAXN];

int query(int k, int node, int l, int r, int ql, int qr) {
    assert(l <= r and ql <= qr);
    if (qr < l or r < ql) {
        return 0;
    }

    if (ql <= l and r <= qr) {
        return tree[k][node];
    }

    int mid = (l + r) >> 1;
    return max(
        query(k, 2 * node, l, mid, ql, qr),
        query(k, 2 * node + 1, mid + 1, r, ql, qr)
    );
}

int query(int k, int l, int r) {
    return query(k, 1, 0, MAXN - 1, l, r);
}

int update(int k, int node, int l, int r, int x, int v) {
    assert(l <= r);
    if (x < l or r < x)
        return tree[k][node];

    if (l == r and l == x)
        return tree[k][node] = max(tree[k][node], v);

    int mid = (l + r) >> 1;
    return tree[k][node] = max(
        update(k, 2 * node, l, mid, x, v),
        update(k, 2 * node + 1, mid + 1, r, x, v)
    );
}

int update(int k, int x, int v) {
    return update(k, 1, 0, MAXN - 1, x, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);

    int x;
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &x);

        update(0, x, query(1, 0, x - 1) + 1);
        update(1, x, query(0, x + 1, MAXN - 1) + 1);
    }

    printf("%d\n", max(query(0, 1, MAXN - 1), query(1, 1, MAXN - 1)));
    return 0;
}
