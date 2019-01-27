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
    // max a * sum b
    multiset<int> ms;
    ll sum = 0LL;
    ll ans = 1e18;
    for (auto& p : v) {
        int a, b;
        tie(a, b) = p;
        sum -= b;
        ms.insert(-b);
        while (ms.size() > k) {
            sum -= *ms.begin();
            ms.erase(ms.begin());
        }

        if (ms.size() == k) {
            ans = min(ans, -1LL * a * sum);
        }
    }
    
    cout << ans << '\n';
    return 0;
}
