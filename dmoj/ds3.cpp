#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

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

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

struct node {
    static constexpr int INF = 1e9 + 7;
    int min_val, min_occ, g;
    node(): min_val(INF), min_occ(1), g(0) {}
    node(int v): min_val(v), min_occ(1), g(v) {}
    node(int v, int o, int g): min_val(v), min_occ(o), g(g) {}

    node operator+(const node& other) const {
        int new_min = min(min_val, other.min_val);
        int new_occ = (new_min == min_val ? min_occ : 0) + (new_min == other.min_val ? other.min_occ : 0);
        int new_gcd = gcd(g, other.g);
        return node(new_min, new_occ, new_gcd);
    }

    int q() const {
        return min_val == g ? min_occ : 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    seg_tree<node> tree(n);
    vector<node> leaves;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        leaves.emplace_back(x);
    }

    tree.set_leaves(leaves);
    char op;
    while (q-- > 0) {
        cin >> op;
        if (op == 'C') {
            int x, v;
            cin >> x >> v;
            --x;
            tree.update(x, node(v));
        } else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            node res = tree.query(l, r);
            if (op == 'M') {
                cout << res.min_val << '\n';
            } else if (op == 'G') {
                cout << res.g << '\n';
            } else {
                cout << res.q() << '\n';
            }
        }
    }
    
    return 0;
}
