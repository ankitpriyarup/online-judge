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
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vi> opts(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            opts[i].push_back(a[j] + i - j);
        }

        sort(all(opts[i]));
        opts[i].erase(unique(all(opts[i])), end(opts[i]));
    }

    constexpr ll INF = 1e18;
    using vl = vector<ll>;
    vl old_dp(opts[0].size(), INF);
    for (int j = 0; j < opts[0].size(); ++j) {
        old_dp[j] = abs(a[0] - opts[0][j]);
        if (j)
            old_dp[j] = min(old_dp[j], old_dp[j - 1]);
    }

    for (int i = 1; i < n; ++i) {
        vl new_dp(opts[i].size(), INF);
        for (int j = 0; j < opts[i].size(); ++j) {
            int x = lower_bound(all(opts[i - 1]), opts[i][j]) - begin(opts[i - 1]);
            assert(x > 0);
            new_dp[j] = abs(a[i] - opts[i][j]) + old_dp[x - 1];

            if (j)
                new_dp[j] = min(new_dp[j], new_dp[j - 1]);
        }

        swap(old_dp, new_dp);
    }

    cout << *min_element(all(old_dp)) << '\n';

    return 0;
}
