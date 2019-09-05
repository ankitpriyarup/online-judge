#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int n;

// segment tree: for each digit, keep track of the smallest two numbers with
// that digit set.
struct node {
    int data[10][2];

    node() {
        memset(data, -1, sizeof(data));
    }

    node(int x) {
        memset(data, -1, sizeof(data));
        int v = x;
        int idx = 0;
        while (x > 0) {
            if (x % 10 > 0) {
                data[idx][0] = v;
            }

            ++idx;
            x /= 10;
        }
    }

    node operator+(const node& other) const {
        node res;
        vi v;
        for (int i = 0; i < 10; ++i) {
            v.clear();
            for (int j = 0; j < 2; ++j) {
                if (data[i][j] != -1)
                    v.push_back(data[i][j]);
                if (other.data[i][j] != -1)
                    v.push_back(other.data[i][j]);
            }
            sort(all(v));
            for (int j = 0; j < 2 and j < v.size(); ++j)
                res.data[i][j] = v[j];
        }

        return res;
    }
};

template <typename T, int N>
struct seg_tree {
    int n;
    T data[2 * N];

    // init the seg tree in O(n)
    void set_leaves(const vector<T>& leaves) {
        for (int i = 0; i < leaves.size(); ++i) {
            data[i + N] = leaves[i];
        }

        for (int i = N - 1; i; --i) {
            data[i] = data[i << 1] + data[i << 1 | 1];
        }
    }

    void update(int i, T v) {
        i += N;
        data[i] = v;
        for (i >>= 1; i; i >>= 1) {
            data[i] = data[i << 1] + data[i << 1 | 1];
        }
    }

    T query(int l, int r) {
        T res_left, res_right;
        for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
            if (l & 1)    res_left  = res_left  + data[l++];
            if (!(r & 1)) res_right = data[r--] + res_right;
        }

        return res_left + res_right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    seg_tree<node, 1<<18> st;

    int q;
    scanf(" %d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf(" %d", &x);
        st.update(i, node(x));
    }

    while (q-- > 0) {
        int op;
        scanf(" %d", &op);
        if (op == 1) {
            int idx, x;
            scanf(" %d %d", &idx, &x);
            --idx;
            st.update(idx, node(x));
        } else {
            int l, r;
            scanf(" %d %d", &l, &r);
            --l; --r;
            node res = st.query(l, r);
            int ans = -1;
            for (int i = 0; i < 10; ++i) {
                if (res.data[i][0] != -1 and res.data[i][1] != -1) {
                    int sum = res.data[i][0] + res.data[i][1];
                    if (ans == -1 or sum < ans)
                        ans = sum;
                }
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}
