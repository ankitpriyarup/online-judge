#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

struct BIT {
    int n;
    vector<ll> data;

    BIT(int n): n(n), data(n + 1, 0) {
    }

    ll query(int x) {
        ll res = 0;
        for (++x; x; x -= (x & -x)) {
            res = max(res, data[x]);
        }
        return res;
    }

    void update(int x, ll v) {
        for (++x; x <= n; x += (x & -x)) {
            data[x] = max(data[x], v);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pii> a(n);
    vector<int> ends(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        ends[2 * i] = a[i].first;
        ends[2 * i + 1] = a[i].second;
    }

    sort(all(ends));
    ends.erase(unique(all(ends)), end(ends));

    BIT f_tree(ends.size());

    // find the largest weight subset of intervals that are increasing
    vector<ll> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        int s = lower_bound(all(ends), a[i].first) - begin(ends);
        int e = lower_bound(all(ends), a[i].second) - begin(ends);
        int w = a[i].second - a[i].first + 1;

        dp[i] = w + f_tree.query(s - 1);
        // cout << "Processing " << s << ' ' << e << " = " << dp[i] << '\n';
        f_tree.update(e, dp[i]);
    }

    cout << *max_element(all(dp)) << '\n';
    
    return 0;
}
