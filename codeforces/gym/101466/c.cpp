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
using slope = tuple<ll, ll, ll>;

set<slope> seen;

ll gcd(ll a, ll b) {
    if (a < 0) return gcd(-a, b);
    if (b < 0) return gcd(a, -b);
    return b ? gcd(b, a % b) : a;
}

void process(ll x, ll y, ll z) {
    ll g = gcd(x, y);
    g = gcd(g, z);
    if (x < 0 or (x == 0 and y < 0) or (x == 0 and y == 0 and z < 0)) {
        g = -g;
    }

    x /= g;
    y /= g;
    z /= g;

    slope s = make_tuple(x, y, z);
    if (seen.find(s) == end(seen)) {
        seen.insert(s);
    }
}

constexpr int MAXN = 5003;
int n;
ll x[MAXN], y[MAXN], z[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld %lld %lld", &x[i], &y[i], &z[i]);
    }

    for (int i = 1; i < n; ++i) {
        process(x[i] - x[0], y[i] - y[0], z[i] - z[0]);
    }

    printf("%lu\n", seen.size());

    return 0;
}
