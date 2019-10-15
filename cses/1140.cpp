#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi a(n), b(n), p(n);
    vi times;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> p[i];
        times.push_back(a[i]);
        times.push_back(b[i]);
    }
    sort(all(times));
    times.erase(unique(all(times)), end(times));
    int m = times.size();

    vector<vi> queries(m);
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(all(times), a[i]) - begin(times);
        b[i] = lower_bound(all(times), b[i]) - begin(times);

        assert(0 <= a[i] && a[i] <= m);
        assert(0 <= b[i] && b[i] <= m);
        queries[b[i]].push_back(i);
    }

    vector<ll> dp(m, 0);
    for (int i = 0; i < m; ++i) {
        if (i > 0) {
            dp[i] = dp[i - 1];
        }

        for (int idx : queries[i]) {
            ll score = p[idx];
            if (a[idx] > 0) {
                score += dp[a[idx] - 1];
            }

            dp[i] = max(dp[i], score);
        }
    }

    cout << dp[m - 1] << '\n';

    return 0;
}
