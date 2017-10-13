#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <tuple>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 1000006;
int n;
int a[MAXN];
int inv[MAXN];
int fear[MAXN];

int max_f_tree[MAXN];

int ans[MAXN];

int max_query(int ind) {
    int res = -1;
    for (int x = ind; x; x -= (x & -x)) {
        res = max(res, max_f_tree[x]);
    }

    return res;
}

void max_update(int ind, int v) {
    for (int x = ind; x < MAXN; x += (x & -x)) {
        max_f_tree[x] = max(max_f_tree[x], v);
    }
}

vector<int> seg_tree[3 * MAXN];

void do_merge(int node) {
    int lchild = 2 * node;
    int rchild = lchild + 1;

    merge(begin(seg_tree[lchild]), end(seg_tree[lchild]),
            begin(seg_tree[rchild]), end(seg_tree[rchild]),
            back_inserter(seg_tree[node]));
}

void build(int node, int l, int r) {
    if (l == r) {
        seg_tree[node].push_back(fear[l]);
    } else {
        int mid = (l + r) >> 1;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        do_merge(node);
    }

    /*
    printf("Node %d\n", node);
    for (auto x : seg_tree[node]) {
        printf("%d ", x);
    }
    printf("\n");
    */
}

// count in range where node < v
int query(int node, int l, int r, int ql, int qr, int v) {
    if (l > qr or r < ql) {
        return 0;
    }

    if (l == ql and r == qr) {
        int sz = seg_tree[node].size();
        int lo = 0;
        int hi = sz - 1;

        if (seg_tree[node][lo] >= v) {
            return 0;
        }

        if (seg_tree[node][hi] < v) {
            return sz;
        }

        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (seg_tree[node][mid] < v) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        // printf("There are %d values < %d in the range %d to %d\n", hi, v, ql, qr);
        return hi;
    }

    int ans = 0;
    int mid = (l + r) >> 1;
    if (mid >= ql) {
        ans += query(2 * node, l, mid, ql, min(qr, mid), v);
    }

    if (mid + 1 <= qr) {
        ans += query(2 * node + 1, mid + 1, r, max(mid + 1, ql), qr, v);
    }

    // printf("There are %d values < %d in the range %d to %d\n", ans, v, ql, qr);
    return ans;
}

int query(int l, int r, int v) {
    return query(1, 1, n, l, r, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    scanf("%d %d", &n, &q); for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        inv[a[i]] = i;
    }

    memset(max_f_tree, -1, sizeof(max_f_tree));
    for (int i = n; i >= 1; --i) {
        int ind = inv[i];
        fear[ind] = max_query(ind);
        max_update(ind, ind);
    }

    /*
    for (int i = 1; i <= n; ++i) {
        printf("%d ", fear[i]);
    }
    printf("\n");
    */

    build(1, 1, n);

    int l, r;
    while (q-- > 0) {
        scanf("%d %d", &l, &r);
        int ans = query(l, r, l);
        printf("%d\n", ans);
    }

    return 0;
}
