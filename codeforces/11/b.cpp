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
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;
constexpr ll MAX = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll x;
    cin >> x;
    x = abs(x);
    ll p = 0;
    ll steps = 0;
    while (p < x) {
        ++steps;
        p += steps;
    }

    // printf("%lld %lld\n", p, x);
    if (p == x) {
        cout << steps << '\n';
    } else {
        while ((p - x) & 1) {
            ++steps;
            p += steps;
        }

        cout << steps << '\n';
    }

    return 0;
}
