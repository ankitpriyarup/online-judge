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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);

    ll k, x;
    while (T-- > 0) {
        scanf("%lld %lld", &k, &x);
        ll num = 1;
        ll den = 1;

        // find the highest one bit set
        ll p = 1;
        while (p <= x) {
            p <<= 1LL;
        }
        p >>= 2LL;
        while (p > 0) {
            if (p & x) {
                num += den;
            } else {
                den += num;
            }

            p >>= 1LL;
        }

        printf("%lld %lld/%lld\n", k, num, den);
    }

    return 0;
}
