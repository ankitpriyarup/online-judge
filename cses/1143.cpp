#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

struct seg_tree {
    const int DEFAULT = -1e9;
    int n;
    vector<int> data;

    seg_tree(const vector<int>& leaves): n(leaves.size()) {
        data.resize(4 * n);
        build(leaves, 1, 0, n - 1);
    }

    int build(const vector<int>& leaves, int node, int l, int r) {
        if (l == r) {
            return data[node] = leaves[l];
        }
        int mid = (l + r) >> 1;
        return data[node] = max(build(leaves, 2 * node, l, mid),
                build(leaves, 2 * node + 1, mid + 1, r));
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l or r < ql) {
            return DEFAULT;
        }
        if (l <= ql and qr <= r) {
            return data[node];
        }

        int mid = (l + r) >> 1;
        return max(
                query(2 * node, l, mid, ql, qr),
                query(2 * node + 1, mid + 1, r, ql, qr));
    }

    int update(int node, int l, int r, int idx, int v) {
        if (idx < l or r < idx) return data[node];
        if (l == r) {
            return data[node] = v;
        }

        int mid = (l + r) >> 1;
        return data[node] = max(
                update(2 * node, l, mid, idx, v),
                update(2 * node + 1, mid + 1, r, idx, v));
    }

    void update(int idx, int v) {
        update(1, 0, n - 1, idx, v);
    }

    int first_ge(int node, int l, int r, int v) {
        if (data[node] < v) {
            return -1;
        }
        if (l == r) return l;

        int mid = (l + r) >> 1;
        if (data[2 * node] >= v) {
            return first_ge(2 * node, l, mid, v);
        } else {
            return first_ge(2 * node + 1, mid + 1, r, v);
        }
    }

    int first_ge(int v) {
        return first_ge(1, 0, n - 1, v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    seg_tree st(a);

    while (q-- > 0) {
        int x;
        cin >> x;
        int idx = st.first_ge(x);
        cout << (idx + 1) << ' ';
        if (idx >= 0) {
            a[idx] -= x;
            st.update(idx, a[idx]);
        }
    }

    return 0;
}
