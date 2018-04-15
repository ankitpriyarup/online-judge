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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, n;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf(" %d", &n);
        unordered_map<ll, int> m;
        m[0LL] = 0;
        ll ans = 0LL;
        ll x;
        while (n-- > 0) {
            scanf(" %lld", &x);
            ans = max(ans, x);

            unordered_map<ll, int> m2;
            for (auto& p : m) {
                ll g = gcd(p.first, x);
                m2[g] = max(m2[g], p.second + 1);
                ans = max(ans, g * m2[g]);
            }

            m2[x] = max(m2[x], 1);
            m = m2;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
