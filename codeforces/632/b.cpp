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
    vector<ll> a(n);
    for (ll& x : a) {
        cin >> x;
    }
    string s;
    cin >> s;

    vector<ll> p(n);
    vector<ll> b(n);
    p[0] = a[0];
    if (s[0] == 'B')
        b[0] = a[0];

    for (int i = 1; i < n; ++i) {
        p[i] = a[i] + p[i - 1];
        b[i] = (s[i] == 'B' ? a[i] : 0) + b[i - 1];
    }

    ll ans = b[n - 1];
    for (int i = 0; i < n; ++i) {
        ll pref = p[i] - b[i];
        ll suff = b[n - 1] - b[i];
        // cout << pref << ' ' << suff << '\n';
        ans = max(ans, pref + suff);

        pref = b[i];
        suff = (p[n - 1] - p[i]) - (b[n - 1] - b[i]);
        // cout << pref << ' ' << suff << '\n';
        ans = max(ans, pref + suff);
    }

    cout << ans << '\n';
    
    return 0;
}
