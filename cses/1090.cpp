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

    int n, x;
    cin >> n >> x;
    multiset<int> ms;
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        ms.insert(y);
    }

    int ans = 0;
    while (!ms.empty()) {
        int a = *begin(ms);
        auto it = ms.upper_bound(x - a);
        if (it != begin(ms) and prev(it) != begin(ms)) {
            ms.erase(prev(it));
        }

        ++ans;
        ms.erase(begin(ms));
    }

    cout << ans << '\n';

    return 0;
}
