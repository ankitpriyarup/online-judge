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

    ll n;
    cin >> n;

    // x = 2^a * 5^b for some a, b
    // round n to the nearest multiple of x
    // probably can't be that many x....
    // log_2(10^18) is 60 or so...

    vector<ll> res;
    for (int i = 0; i <= 61; ++i) {
        for (int j = 0; j <= 30; ++j) {
            ll x = 1;
            for (int v = 0; v < i; ++v) {
                x *= 2;
                if (x > n) {
                    x = -1;
                    break;
                }
            }
            if (x < 0) continue;

            for (int v = 0; v < j; ++v) {
                x *= 5;
                if (x > n) {
                    x = -1;
                    break;
                }
            }
            if (x < 0) continue;

            if (n % x == 0)
                res.push_back(x);
        }
    }

    sort(all(res));
    cout << res.size() << '\n';
    for (auto& v : res) {
        cout << v << '\n';
    }
    
    return 0;
}
