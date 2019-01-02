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

template <typename T>
struct BIT {
    int n;
    vector<T> f_tree;
    BIT(int n): n(n) {
        f_tree.resize(n + 2);
    }

    void update(int x, T v) {
        ++x;
        for (; x <= n + 1; x += (x & -x)) {
            f_tree[x] = f_tree[x] + v;
        }
    }

    T query(int x) const {
        ++x;
        T res = 0;
        for (; x; x -= (x & -x)) {
            res = res + f_tree[x];
        }

        return res;
    }

    inline T query(int l, int r) const {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    constexpr int MAXN = 100000;
    BIT<ll> by_ind(n), by_val(MAXN);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        by_ind.update(i, a[i]);
        by_val.update(a[i], 1);
    }

    char op;
    int x, v, l, r;
    while (q-- > 0) {
        cin >> op;
        if (op == 'C') {
            cin >> x >> v;
            --x;
            by_ind.update(x, v - a[x]);
            by_val.update(a[x], -1);
            by_val.update(v, 1);

            a[x] = v;
        } else if (op == 'S') {
            cin >> l >> r;
            --l; --r;
            cout << by_ind.query(l, r) << '\n';
        } else if (op == 'Q') {
            cin >> v;
            cout << by_val.query(v) << '\n';
        }
    }

    return 0;
}
