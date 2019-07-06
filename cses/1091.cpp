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

    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        ms.insert(h);
    }

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        auto it = ms.upper_bound(t);
        if (ms.empty() or it == begin(ms)) {
            cout << "-1\n";
        } else {
            it = prev(it);
            cout << *it << "\n";
            ms.erase(it);
        }
    }

    return 0;
}
