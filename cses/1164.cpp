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

    using interval = tuple<int, int, int>;
    vector<interval> intervals;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        intervals.emplace_back(b, a, i);
    }
    sort(all(intervals));
    set<pii> ends;
    vi ans(n, -1);
    for (auto& interval : intervals) {
        int b, a, i;
        tie(b, a, i) = interval;

        auto it = ends.lower_bound({a, -1});
        if (it == begin(ends)) {
            int k = ends.size();
            ans[i] = k;
            ends.emplace(b, k);
        } else {
            it = prev(it);
            int k = it->second;
            ends.erase(it);

            ans[i] = k;
            ends.emplace(b, k);
        }
    }

    cout << (*max_element(all(ans)) + 1) << '\n';
    for (int i = 0; i < n; ++i) {
        cout << (ans[i] + 1) << ' ';
    }

    return 0;
}
