#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

struct MedianSet {
    set<ll> lo, hi;
    ll lo_sum, hi_sum;

    MedianSet(): lo_sum(0), hi_sum(0) {}

    ll get_median() const {
        assert(!lo.empty());
        return *prev(end(lo));
    }

    void insert(ll x) {
        hi.insert(x);
        hi_sum += x;
        balance();
    }

    void pop() {
        // dont rebalance because inserr after
        lo_sum -= *begin(lo);
        lo.erase(begin(lo));
    }

    ll solve() const {
        ll L = lo.size() - 1;
        ll R = hi.size();
        ll m = get_median();

        ll left = m * L - (L * (L + 1)) / 2 - lo_sum + m;
        ll right = hi_sum - (m * R + R * (R + 1) / 2);

        return left + right;
    }

    void balance() {
        // invariant: lo.size() >= hi.size()
        // lo.size() <= hi.size() + 1
        // 3 2, 3 3
        while (lo.size() < hi.size()) {
            auto it = begin(hi);
            lo_sum += *it;
            hi_sum -= *it;

            lo.insert(*it);
            hi.erase(it);
        }
        while (hi.size() + 1 < lo.size()) {
            auto it = prev(end(lo));
            lo_sum -= *it;
            hi_sum += *it;

            hi.insert(*it);
            lo.erase(it);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        vi v(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            v[i] = a[i];
        }
        sort(all(v));
        v.erase(unique(all(v)), end(v));

        int m = v.size();
        vector<vi> occ(m);
        for (int i = 0; i < n; ++i) {
            int idx = lower_bound(all(v), a[i]) - begin(v);
            occ[idx].push_back(i);
        }

        constexpr ll INF = 1e18;
        ll ans = INF;
        for (const vi& row : occ) {
            if (row.size() < k)
                continue;

            MedianSet ms;
            for (int i = 0; i < k; ++i) {
                // xxxox (1) xxoxx (2), so pos matters
                // everything should go to the median
                ms.insert(row[i]);
            }
            // okay, say the median is m
            // (m - 1) - lo[-1] + (m - 2) - lo[-2] + ...
            // hi[0] - (m + 1) + hi[1] - (m + 2) + ...
            // say lo has L and hi has R 
            // (m - 1) + (m - 2) + ... + (m - L) - sum(lo)
            // sum(hi) - (m + 1) - (m + 2) - ... (m + R)
            ans = min(ans, ms.solve());
            for (int i = k; i < row.size(); ++i) {
                ms.pop();
                ms.insert(row[i]);
                ans = min(ans, ms.solve());
            }
        }

        cout << (ans == INF ? -1 : ans) << '\n';
    }
    
    return 0;
}
