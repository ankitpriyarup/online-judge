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
    if (x <= 1) return false;
    if (x == 2) return true;
    if (!(x & 1)) return false;
    for (ll d = 3; d * d <= x; d += 2) {
        if (x % d == 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    scanf(" %lld", &n);
    while (!is_prime(n)) ++n;
    
    printf("%lld\n", n);

    return 0;
}
