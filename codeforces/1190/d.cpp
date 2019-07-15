#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

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
        for (; x > 0; x -= (x & -x)) {
            res = res + f_tree[x];
        }

        return res;
    }

    inline T query(int l, int r) const {
        return query(r) - query(l - 1);
    }
};

inline ll nc2(ll x) {
    return x * (x + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pii> pts;
    vector<int> all_xs;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        pts.emplace_back(-y, x);
        all_xs.push_back(x);
    }

    sort(all(pts));
    sort(all(all_xs));
    all_xs.erase(unique(all(all_xs)), end(all_xs));
    int m = all_xs.size();
    BIT<int> f_tree(m);

    int cur = 0;
    ll ans = 0LL;
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n and pts[j].first == pts[i].first)
            ++j;

        // how many pairs of points include some point at the current y?
        vi xs;
        for (int k = i; k < j; ++k) {
            int idx = lower_bound(all(all_xs), pts[k].second) - begin(all_xs);
            xs.push_back(idx);
        }
        sort(all(xs));

        // cout << "y = " << -pts[i].first  << '\n';

        //cout << " before "  << f_tree.query(xs[0] - 1) << '\n';
        // cout << " after "  << f_tree.query(xs.back() + 1, m - 1) << '\n';
        ans -= nc2(f_tree.query(xs[0] - 1));
        ans -= nc2(f_tree.query(xs.back() + 1, m - 1));

        for (int k = 1; k < xs.size(); ++k) {
            int lo = xs[k - 1];
            int hi = xs[k];

            // cout << " middle " << f_tree.query(lo + 1, hi - 1) << '\n';
            ans -= nc2(f_tree.query(lo + 1, hi - 1));
        }
        
        for (int k = 0; k < xs.size(); ++k)  {
            if (f_tree.query(xs[k], xs[k]) == 0) { 
                // cout << "insert at " << all_xs[xs[k]] << '\n';
                ++cur;
                f_tree.update(xs[k], 1);
            }
        }

        ans += nc2(cur);

        i = j;
    }

    cout << ans << '\n';
    
    return 0;
}
