#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool is_prime_power(ll q) {
    if (q == 1) return false;

    for (ll d = 2; d * d <= q; ++d) {
        if (q % d == 0) {
            while (q % d == 0) {
                q /= d;
            }

            return q == 1;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll q;
    cin >> q;
    cout << (is_prime_power(q) ? "yes" : "no") << '\n';
    
    return 0;
}
