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
    ll h;
    cin >> n >> h;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int lo = 1;
    int hi = n + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        vector<ll> b;
        for (int i = 0; i < mid; ++i) {
            b.push_back(a[i]);
        }
        sort(all(b));
        reverse(all(b));
        ll tot = 0;
        for (int i = 0; i < mid; i += 2) {
            tot += b[i];
        }

        if (tot <= h) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << '\n';

    return 0;
}
