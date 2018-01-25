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

constexpr int MAXN = 500005;
int n;
int a[MAXN];
int tree[4 * MAXN];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
}

bool query(int node, int l, int r, int ql, int qr, int x, bool v) {
    if (l == ql and r == qr) {
        if (tree[node] % x == 0) {
            return true;
        }

        if (l == r) {
            return v;
        }

        int mid = (l + r) >> 1;
        if (v)
            return (query(2 * node, l, mid, l, mid, x, 1) and query(2 * node + 1, mid + 1, r, mid + 1, r, x, 0))
                or (query(2 * node, l, mid, l, mid, x, 0) and query(2 * node + 1, mid + 1, r, mid + 1, r, x, 1));
        else
            return query(2 * node, l, mid, l, mid, x, 0) and query(2 * node + 1, mid + 1, r, mid + 1, r, x, 0);
    }

    int mid = (l + r) >> 1;
    if (ql <= mid and mid < qr) {
        if (v)
            return (query(2 * node, l, mid, ql, min(mid, qr), x, 1) and query(2 * node + 1, mid + 1, r, max(ql, mid + 1), qr, x, 0))
                or (query(2 * node, l, mid, ql, min(mid, qr), x, 0) and query(2 * node + 1, mid + 1, r, max(ql, mid + 1), qr, x, 1));
        else
            return query(2 * node, l, mid, ql, min(mid, qr), x, 0) and query(2 * node + 1, mid + 1, r, max(ql, mid + 1), qr, x, 0);
    } else if (ql <= mid) {
        return query(2 * node, l, mid, ql, min(mid, qr), x, v);
    } else {
        return query(2 * node + 1, mid + 1, r, max(ql, mid + 1), qr, x, v);
    }
}

bool query(int l, int r, int x) {
    return query(1, 1, n, l, r, x, 1);
}

void update(int node, int l, int r, int ind, int v) {
    if (l == ind and r == ind) {
        tree[node] = v;
        return;
    }

    int mid = (l + r) >> 1;
    if (ind <= mid) {
        update(2 * node, l, mid, ind, v);
    } else {
        update(2 * node + 1, mid + 1, r, ind, v);
    }

    tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
}

void update(int ind, int v) {
    update(1, 1, n, ind, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    build(1, 1, n);

    int q;
    scanf("%d", &q);

    int kind, l, r, x;
    int ind, v;
    while (q-- > 0) {
        scanf("%d", &kind);
        if (kind == 1) {
            scanf("%d %d %d", &l, &r, &x);
            printf("%s\n", (query(l, r, x)) ? "YES" : "NO");
        } else {
            scanf("%d %d", &ind, &v);
            update(ind, v);
        }
    }
    
    return 0;
}
