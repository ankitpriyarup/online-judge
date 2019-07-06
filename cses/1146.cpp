#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

ll solve(ll x) {
    if (x < 2) {
        return x;
    }

    if ((x & 1) == 0) {
        return __builtin_popcountll(x) + solve(x - 1);
    }
    return ((x + 1) >> 1) + (solve(x >> 1) << 1);
}

// 11
// 10
// 01
// 00

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll x;
    cin >> x;

    cout << solve(x) << '\n';

    return 0;
}
