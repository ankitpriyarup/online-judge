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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);

    ll res = 1LL;
    constexpr ll MOD = 1e11;
    int twos = 0;
    int fives = 0;
    for (int i = 2; i <= n; ++i) {
        int x = i;
        while (x % 5 == 0) {
            x /= 5;
            ++fives;
        }
        while (x % 2 == 0) {
            x >>= 1;
            ++twos;
        }

        res *= x;
        while (res % 10 == 0) {
            res /= 10;
        }

        res %= MOD;
    }

    for (int i = 0; i < twos - fives; ++i) {
        res = 2LL * res % MOD;
    }

    if (n <= 6)
        printf("%lld\n", res);
    else
        printf("%03lld\n", res % 1000);

    return 0;
}
