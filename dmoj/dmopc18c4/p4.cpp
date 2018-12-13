#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
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

constexpr int MAXN = 200005;
int n;
ll a[MAXN];

vector<ll> values[4 * MAXN];
vector<ll> p[4 * MAXN];

void do_merge(int node) {
    int lchild = 2 * node;
    int rchild = lchild + 1;

    merge(begin(values[lchild]), end(values[lchild]),
            begin(values[rchild]), end(values[rchild]),
            back_inserter(values[node]));

    assert (!values[node].empty());

    p[node].push_back(values[node][0]);
    for (int i = 1; i < (int)(values[node].size()); ++i) {
        p[node].push_back(p[node].back() + values[node][i]);
    }

    assert(p[node].size() == values[node].size());
}

void build(int node, int l, int r) {
    if (l == r) {
        values[node].push_back(a[l]);
        p[node].push_back(a[l]);
    } else {
        int mid = (l + r) >> 1;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        do_merge(node);
    }
}

ll query(int node, int l, int r, int ql, int qr, ll k) {
    if (l > qr or r < ql) {
        return 0;
    }
    assert (!values[node].empty());

    if (l == ql and r == qr) {
        if (values[node].back() < k) {
            return -p[node].back();
        }
        if (values[node][0] >= k) {
            return p[node].back();
        }

        int lo = 0;
        int hi = p[node].size();
        --hi;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            if (values[node][mid] < k) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return p[node].back() - 2LL * p[node][lo];
    }

    ll ans = 0;
    int mid = (l + r) >> 1;
    if (mid >= ql) {
        ans += query(2 * node, l, mid, ql, min(qr, mid), k);
    }

    if (mid + 1 <= qr) {
        ans += query(2 * node + 1, mid + 1, r, max(mid + 1, ql), qr, k);
    }

    return ans;
}

ll query(int l, int r, ll k) {
    return query(1, 1, n, l, r, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }

    build(1, 1, n);

    int l, r;
    ll k;
    while (q-- > 0) {
        scanf("%d %d %lld", &l, &r, &k);
        ll ans = query(l, r, k);
        printf("%lld\n", ans);
    }

    return 0;
}
