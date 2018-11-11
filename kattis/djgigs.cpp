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
using pll = pair<ll, ll>;
// end, start, city, money
using gig = tuple<ll, ll, ll, ll>;

constexpr ll INF = 1e18;

vector<vector<ll>> read_dists(int k, int r) {
    vector<vector<ll>> dists(k, vector<ll>(k, INF));
    for (int i = 0; i < k; ++i) {
        dists[i][i] = 0;
    }

    int a, b;
    ll c;
    for (int i = 0; i < r; ++i) {
        cin >> a >> b >> c;
        assert(1 <= a and a <= k);
        assert(1 <= b and b <= k);
        assert(a != b);

        --a;
        --b;

        assert(dists[a][b] == INF);
        assert(dists[b][a] == INF);

        dists[a][b] = dists[b][a] = c;
    }

    // run floyd_warshall to get actual distances
    for (int l = 0; l < k; ++l) {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                dists[i][j] = min(dists[i][j], dists[i][l] + dists[l][j]);
            }
        }
    }

    return dists;
}

vector<gig> read_gigs(int g, int k) {
    int v, s, e, m;
    vector<gig> gigs;
    for (int i = 0; i < g; ++i) {
        cin >> v >> s >> e >> m;
        assert (1 <= v and v <= k);
        assert (s < e);

        --v;
        gigs.emplace_back(e, s, v, m);
    }

    return gigs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int g, k, r;
    cin >> g >> k >> r;

    vector<vector<ll>> dists = read_dists(k, r);
    vector<gig> gigs = read_gigs(g, k);

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            assert(dists[i][j] == dists[j][i]);
        }
    }

    sort(begin(gigs), end(gigs));

    // Each city has its own stack
    // The stack is a set of pairs {end_time, money}, sorted by end time
    // as end time increases, so does money.
    vector<vector<pll>> dp(k);

    ll ans = 0;
    ll s, e, v, m;
    for (const auto& gig_event : gigs) {
        tie(e, s, v, m) = gig_event;

        ll prev_money = -INF;

        // consider straight from the start
        if (dists[0][v] != INF and dists[0][v] <= s) {
            prev_money = 0;
        }

        for (int venue = 0; venue < k; ++venue) {

            // Need to come from a previous event
            if (dp[venue].empty() or dists[venue][v] == INF) {
                continue;
            }
            ll max_end = s - dists[venue][v];

            if (dp[venue][0].first > max_end) {
                continue;
            }

            int lo = 0;
            int hi = dp[venue].size();
            while (lo + 1 < hi) {
                int mid = (lo + hi) >> 1;
                assert(0 <= mid and mid < dp[venue].size());
                if (dp[venue][mid].first > max_end) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }

            prev_money = max(prev_money, dp[venue][lo].second);
        }

        // Can't do this gig at all
        if (prev_money == -INF) {
            continue;
        }

        ll new_money = prev_money + m;
        ans = max(ans, new_money);
        if (dp[v].empty() or (dp[v].back().first < e and dp[v].back().second < new_money)) {
            dp[v].emplace_back(e, new_money);
        }
    }

    cout << ans << '\n';

    return 0;
}
