#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

ll f(ll x) {
    ll ans = x;
    while (x) {
        ans += (x % 10);
        x /= 10;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    ll n;
    scanf("%lld", &n);

    vector<ll> ans;
    for (ll i = max(0LL, n - 100); i < n; ++i) {
        if (f(i) == n) {
            ans.push_back(i);
        }
    }

    printf("%d\n", ans.size());
    for (auto x : ans) {
        printf("%lld\n", x);
    }

    return 0;
}
