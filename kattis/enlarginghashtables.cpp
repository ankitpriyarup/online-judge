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

bool is_prime(ll x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if ((x & 1) == 0) return false;
    for (ll i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    while (scanf("%lld", &n) == 1) {
        if (!n) break;

        bool n_prime = is_prime(n);
        for (ll x = 2LL * n + 1; ; x += 2) {
            if (is_prime(x)) {
                printf("%lld", x);
                if (!n_prime)
                    printf(" (%lld is not prime)", n);
                printf("\n");

                break;
            }
        }
    }

    return 0;
}
