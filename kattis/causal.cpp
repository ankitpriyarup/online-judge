#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int works(const vector<pair<ll, ll>>& events, ll t0) {
    vector<pair<ll, ll>> intervals;
    for (auto& p : events) {
        ll t = p.first;
        ll x = p.second;
        ll dt = t - t0;
        if (dt < 0)
            return 1e9;

        ll x0 = x - dt;
        ll x1 = x + dt;
        intervals.emplace_back(x0, x1);
    }

    sort(all(intervals), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    // find the smallest number of points needed to cover the intervals
    vector<ll> cover = {intervals[0].second};
    for (auto& interval : intervals) {
        ll l, r;
        tie(l, r) = interval;
        if (cover.back() < l) {
            cover.push_back(r);
        }
    }

    return cover.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    int tc = 1;
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;

        vector<pair<ll, ll>> events(n);
        for (int i = 0; i < n; ++i) {
            cin >> events[i].first >> events[i].second;
        }

        ll lo = -1e18;
        ll hi = 1e18;
        while (lo + 1 < hi) {
            ll mid = (lo + hi) / 2;
            if (works(events, mid) <= m) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        cout << "Case " << tc++ << ": " << lo << '\n';
    }

    return 0;
}
