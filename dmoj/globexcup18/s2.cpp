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
using pii = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<pii> v;
    ll tot = 0LL;
    ll goal = k * n;
    for (ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        v.emplace_back(y, m - x);
        tot += x;
    }

    // cout << "tot / goal: " << tot << " / " << goal << '\n';

    sort(begin(v), end(v));

    ll ans = 0LL;
    for (auto& p : v) {
        ll cost, rem;
        tie(cost, rem) = p;
        ll take = max(0LL, min(goal - tot, rem));
        tot += take;
        ans += 1LL * take * cost;
    }
    cout << ans << '\n';
    
    return 0;
}
