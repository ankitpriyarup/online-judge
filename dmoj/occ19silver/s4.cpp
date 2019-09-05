#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 400005;
constexpr int INF = 1e9 + 7;

int n;
int a[MAXN];

// data needed: prefix, suffix, answer, values at left and right, size
struct cell {
    int pref, suff, ans;
    int left, right, sz;

    cell(): pref(0), suff(0), ans(0), left(0), right(0), sz(0) {}
    cell(int x): pref(1), suff(1), ans(1), left(x), right(x), sz(1) {}

    cell operator+(const cell& o) const {
        cell res;
        res.pref = pref;
        if (pref == sz and right <= o.left) {
            res.pref += o.pref;
        }

        res.suff = o.suff;
        if (o.suff == o.sz and right <= o.left) {
            res.suff += suff;
        }

        res.ans = max(ans, o.ans);
        if (right <= o.left) {
            res.ans = max(res.ans, suff + o.pref);
        }

        res.left = left;
        res.right = o.right;
        res.sz = sz + o.sz;

        return res;
    }
};

template <typename T>
struct seg_tree {
    int n;
    vector<T> data;
    seg_tree(int n): n(n) {
        data.resize(n << 1);
    }

    // init the seg tree in O(n)
    void set_leaves(const vector<T>& leaves) {
        for (int i = 0; i < n; ++i) {
            data[i + n] = leaves[i];
        }

        for (int i = n - 1; i; --i) {
            data[i] = data[i << 1] + data[i << 1 | 1];
        }
    }

    void update(int i, T v) {
        i += n;
        data[i] = v;
        for (i >>= 1; i; i >>= 1) {
            data[i] = data[i << 1] + data[i << 1 | 1];
        }
    }

    T query(int l, int r) {
        T res_left, res_right;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1)    res_left  = res_left  + data[l++];
            if (!(r & 1)) res_right = data[r--] + res_right;
        }

        return res_left + res_right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> n >> q;

    vector<cell> leaves(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        leaves[i] = cell(x);
    }

    seg_tree<cell> st(n);
    st.set_leaves(leaves);

    cout << st.query(0, n - 1).ans << '\n';
    while (q-- > 0) {
        int idx, x;
        cin >> idx >> x;
        --idx;
        st.update(idx, cell(x));
        cout << st.query(0, n - 1).ans << '\n';
    }
    
    return 0;
}
