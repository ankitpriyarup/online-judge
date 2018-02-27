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

ll tau(ll n) {
    ll ans = 1;
    for (ll d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            ll count = 0;
            while (n % d == 0) {
                ++count;
                n /= d;
            }

            ans *= count + 1LL;
        }
    }

    if (n > 1)
        ans *= 2LL;

    return ans;
}

ll solve(int n) {
    return (tau(1LL * n * n) + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char s[100000];
    while (scanf("%s", s) == 1) {
        int n = atoi(&s[2]);
        printf("%lld\n", solve(n));
    }
    
    return 0;
}
