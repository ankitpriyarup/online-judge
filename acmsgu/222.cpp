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

int fact[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= 10; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    int n, k;
    scanf(" %d %d", &n, &k);
    ll res = 0LL;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int pc = __builtin_popcount(mask);
        if (pc == k) {
            // n choose k
            res += fact[n] / fact[n - k];
        }
    }

    printf("%lld\n", res);

    return 0;
}
