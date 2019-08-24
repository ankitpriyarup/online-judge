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
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    ll lo = 0;
    ll hi = 1e12;

    int m = n / 2;

    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        vector<ll> b;
        for (ll& x : a) {
            if (x < mid)
                b.push_back(x);
        }

        ll cost = 0LL;
        sort(all(b));
        while (b.size() > m) {
            cost += mid - b.back();
            b.pop_back();
        }

        if (cost <= k) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << '\n';
    
    return 0;
}
