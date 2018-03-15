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

ll base[] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};

ll digsum(ll x) {
    ll oldx = x;
    ll res = 0LL;
    while (x) {
        res += (x % 10);
        x /= 10;
    }

    return res;
}

ll f(ll cap) {
    if (cap <= 0)
        return 0;

    if (cap <= 9)
        return base[cap];

    ll res = 0LL;
    while (cap % 10 != 9) {
        res += digsum(cap);
        --cap;
    }

    return res + ((cap + 1) / 10) * 45LL + f(cap / 10) * 10LL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    ll a, b;
    while (T-- > 0) {
        scanf(" %lld %lld", &a, &b);
        ll ans = f(b) - f(a - 1);
        // printf("f(%lld) = %lld\n", b, f(b));
        // printf("f(%lld) = %lld\n", a - 1, f(a - 1));
        printf("%lld\n", ans);
    }
    
    return 0;
}
