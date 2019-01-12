#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

// 0 indexed template
template <typename T>
struct BIT {
    int n;
    vector<T> f_tree;
    BIT(int n): n(n) {
        f_tree.assign(n + 1, 0);
    }

    void update(int x, T v) {
        ++x;
        for (; x <= n; x += (x & -x)) {
            f_tree[x] = max(f_tree[x], v);
        }
    }

    T query(int x) const {
        ++x;
        T res = 0;
        for (; x; x -= (x & -x)) {
            res = max(res, f_tree[x]);
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    BIT<ll> dp(n);

    vi h(n);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        --h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        ll prev_val = dp.query(h[i]);
        dp.update(h[i], prev_val + a[i]);
    }

    cout << dp.query(n - 1) << '\n';
    
    return 0;
}
