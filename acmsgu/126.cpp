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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll fast(ll a, ll b) {
    ll g = gcd(a, b);
    a /= g;
    b /= g;
    ll s = a + b;
    ll p = 1LL;
    int ans = 0;
    while (p < s) {
        p *= 2;
        ++ans;
    }

    return p == s ? ans : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll a, b;
    scanf(" %lld %lld", &a, &b);
    printf("%lld\n", fast(a, b));

    return 0;
}
