#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

ll sum(ll lo, ll hi) {
    return hi * (hi + 1) / 2 - lo * (lo - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, k, i, j;
    scanf("%lld %lld %lld %lld", &n, &k, &i, &j);

    ll a = (i <= k) ? i + n - k : i - k;
    ll b = (j <= k) ? j + n - k : j - k;

    ll ans;
    if (a <= b) {
        ans = sum(a, b);
    } else {
        ans = sum(a, n) + sum(1, b);
    }

    printf("%lld\n", ans);

    return 0;
}
