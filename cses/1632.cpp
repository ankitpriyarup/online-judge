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

    int n, k;
    cin >> n >> k;
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second >> v[i].first;
    }

    sort(all(v));
    multiset<int> ms;
    for (int i = 0; i < k; ++i) {
        ms.insert(0);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = ms.upper_bound(v[i].second);
        if (it == begin(ms)) {
            continue;
        }

        ++ans;
        it = prev(it);
        ms.erase(it);
        ms.insert(v[i].first);
    }

    cout << ans << '\n';
    
    return 0;
}
