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

    int p;
    ll t;
    cin >> p >> t;
    t = min(t, 2LL * p);
    vi v = {0};
    int c = 0;
    for (int i = 1; i <= t; ++i) {
        c += i;
        while (c >= p)
            c -= p;
        v.push_back(c);
    }

    sort(all(v));
    int ans = unique(all(v)) - begin(v);

    cout << ans << '\n';

    return 0;
}
