#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

// Find the best rational approximation for x given that the denominator cannot
// exceed m. Taken from KACTL.
pair<ll, ll> approx(ld x, ll m) {
    ll last_p = 0;
    ll last_q = 1;
    ll p = 1;
    ll q = 0;
    ll INF = numeric_limits<ll>::max();
    ld y = x;
    while (true) {
        ll lim = min(p ? (m - last_p) / p : INF, q ? (m - last_q) / q : INF);
        ll a = static_cast<ll>(y);
        ll b = min(a, lim);
        ll np = b * p + last_p;
        ll nq = b * q + last_q;

        if (a > b) {
            ld new_cost = abs(x - static_cast<ld>(np) / static_cast<ld>(nq));
            ld old_cost = abs(x - static_cast<ld>(p) / static_cast<ld>(q));
            return new_cost < old_cost ? pair<ll, ll>{np, nq} : pair<ll, ll>{p, q};
        }

        y = 1 / (y - static_cast<ld>(a));
        if (abs(y) > 3 * m) {
            return {np, nq};
        }

        last_p = p; p = np;
        last_q = q; q = nq;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    int k, m;
    ld x;
    while (T-- > 0) {
        cin >> k >> m >> x;

        auto ans = approx(x, m);

        cout << k << " " << ans.first << "/" << ans.second << '\n';
    }
    
    return 0;
}
