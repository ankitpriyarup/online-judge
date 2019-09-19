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
    BIT(int n): n(n), data(n + 1, 0) {}

    ll query(int x) {
        ll res = 0;
        for (x += 1; x > 0; x -= (x & -x)) {
            res += data[x];
        }

        return res;
    }

    void update(int x, int v) {
        for (x += 1; x <= n; x += (x & -x)) {
            data[x] += v;
        }
    }

    ll query(int a, int b) {
        if (a == b) return 0;
        if (a < b) {
            return query(b - 1) - query(a - 1);
        } else {
            return query(a - 1) - query(b - 1);
        }
    }
};

void solve() {
    int n;
    cin >> n;

    vi loc(n, -1);
    BIT bit(n);
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        --x;
        bit.update(i, x + 1);
        loc[x] = i;

        tot += x + 1;
    }

    ll ans = 0;
    int pos = 0;
    for (int val = 0; val < n; ++val) {
        int new_pos = loc[val];
        ll cost = bit.query(pos, new_pos);
        cost = min(cost, tot - cost);

        // cerr << "COST = " << cost << '\n';

        ans += cost;

        bit.update(new_pos, -(val + 1));
        tot -= val + 1;
        pos = (new_pos + 1) % n;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    
    return 0;
}
