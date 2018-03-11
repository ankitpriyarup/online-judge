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

    ll n, p;
    scanf("%lld %lld", &n, &p);
    ll sum = 0;
    ll x;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        sum += x;
    }

    if (p == 100) {
        printf("impossible\n");
        return 0;
    }

    ll ans = 0;
    while (sum < p * n) {
        sum += 100LL;
        ++ans;
        ++n;
    }

    printf("%lld\n", ans);

    return 0;
}
