#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool is_prime(ll x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (!(x & 1)) return false;
    for (int d = 3; 1LL * d * d <= x; d += 2) {
        if (x % d == 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        ll n;
        cin >> n;
        // is n a perfect square with non-prime square root?
        ll x = sqrt(n);
        ll root = -1;
        for (int v = x - 3; v <= x + 3; ++v) {
            if (1LL * v * v == n) {
                root = v;
                break;
            }
        }

        if (root == -1 or is_prime(root)) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    
    return 0;
}
