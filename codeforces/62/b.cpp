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

    int q, k;
    cin >> q >> k;
    vector<vi> occ(26);

    string s;
    cin >> s;
    for (int i = 0; i < k; ++i) {
        occ[s[i] - 'a'].push_back(i);
    }

    while (q-- > 0) {
        string t;
        cin >> t;

        ll cost = 0LL;
        for (int i = 0; i < static_cast<int>(t.size()); ++i) {
            int x = t[i] - 'a';
            auto it = lower_bound(all(occ[x]), i);
            int cur = 10 * k;
            if (it != end(occ[x])) {
                cur = min(cur, abs(*it - i));
            }

            if (it != begin(occ[x])) {
                cur = min(cur, abs(i - *prev(it)));
            }

            if (cur == 10 * k) {
                assert(occ[x].empty());
                cur = t.size();
            }

            cost += cur;
        }

        cout << cost << '\n';
    }

    return 0;
}
