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

using ll = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll fact[60];
    fact[0] = 1;
    ll mod = (1ULL << 32);
    for (ll i = 1; i <= 50; ++i) {
        fact[i] = (1ULL * fact[i - 1] * i) % mod;
    }

    int T;
    scanf("%d", &T);
    ll n;
    while (T-- > 0) {
        scanf("%llu", &n);
        if (n <= 50) {
            printf("%llu\n", fact[n]);
        } else {
            printf("0\n");
        }
    }

    return 0;
}
