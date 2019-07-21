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

    ll n, m;
    cin >> n >> m;
    
    ll mask = (1LL << n) - 1;

    while (m-- > 0) {
        ll v, k;
        cin >> v >> k;
        k %= n;
        for (ll i = 0; i < k; ++i) {
            ll nv = (v << 1) & mask;
            if (v & (1LL << (n - 1))) {
                nv |= 1;
            }

            v = nv;
        }

        cout << v << '\n';
    }
    
    return 0;
}
