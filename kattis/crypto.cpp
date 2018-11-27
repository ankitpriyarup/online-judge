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

    ll x;
    scanf(" %lld", &x);

    ll ans = x;
    int best = 0;

    for (ll d = 2; d * d <= x; ++d) {
        int pow = 0;
        ll y = x;
        while (y % d == 0) {
            ++pow;
            y /= d;
        }

        if (pow > best) {
            best = pow;
            ans = d;
        }
    }

    printf("%lld\n", ans);
    
    return 0;
}
