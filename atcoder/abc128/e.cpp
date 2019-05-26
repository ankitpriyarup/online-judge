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

    int n, q;
    cin >> n >> q;

    vector<tuple<int, int, int>> events;
    for (int i = 0; i < n; ++i) {
        int s, t, x;
        cin >> s >> t >> x;

        events.emplace_back(s - x, 0, x);
        events.emplace_back(t - x, 1, x);
    }

    vi ans(q);
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        events.emplace_back(x, 2, i);
    }

    sort(all(events));
    multiset<int> ms;
    for (auto& evt : events) {
        int x, op, y;
        tie(x, op, y) = evt;

        if (op == 2) {
            // cout << "QUERY " << x << '\n';
            // query
            ans[y] = ms.empty() ? -1 : *begin(ms);
        } else if (op == 0) {
            // cout << "OPEN " << y << '\n';
            // open interval
            ms.insert(y);
        } else if (op == 1) {
            // cout << "CLOSE " << y << '\n';
            // remove interval
            ms.erase(ms.find(y));
        }
    }

    for (int x : ans) {
        cout << x << '\n';
    }

    return 0;
}
