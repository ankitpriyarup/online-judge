#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr ll INF = 1e18 + 1e2;

int query(const vector<int>& f_tree, int x) {
    int res = 0;
    for (; x; x -= (x & -x)) {
        res = max(res, f_tree[x]);
    }

    return res;
}

void update(vector<int>& f_tree, int x, int v) {
    for (; x < f_tree.size(); x += (x & -x)) {
        f_tree[x] = max(f_tree[x], v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> p(m), r(m);
    for (int i = 0; i < m; ++i) 
        cin >> p[i];
    for (int i = 0; i < m; ++i) 
        cin >> r[i];

    vi c(n);
    vector<ll> t(n);
    vector<ll> times = {0};
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> t[i];
        --c[i];
        ll bef = t[i] - p[c[i]];
        if (bef > 0)
            times.push_back(bef);
        ll aft = t[i] + r[c[i]];
        if (aft < INF)
            times.push_back(aft);
    }

    sort(all(times));
    times.erase(unique(all(times)), end(times));
    vector<int> f_tree(times.size(), 0);

    // need a data structure that can handle the following:
    // insert (time, dp[i])
    // for all t <= time, what is max dp?
    // looks like a honking fenwick tree. yeeeeet
    vi by_c(m, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        if (p[c[i]] <= t[i]) {
            cur = max(cur, 1 + by_c[c[i]]);
        }
        if (t[i] - p[c[i]] > 0) {
            ll x = t[i] - p[c[i]];
            int idx = lower_bound(all(times), x) - begin(times);
            cur = max(cur, 1 + query(f_tree, idx));
        }
        int idx = lower_bound(all(times), t[i] + r[c[i]]) - begin(times);
        update(f_tree, idx, cur);
        ans = max(ans, cur);
        by_c[c[i]] = max(by_c[c[i]], cur);
    }

    cout <<ans << '\n';
    return 0;
}
