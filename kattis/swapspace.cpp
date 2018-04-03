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
using pii = pair<ll, ll>;

int sgn(ll x) {
    return x < 0 ? 1 : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    ll x, y;
    vector<pii> drives;
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &x, &y);
        drives.emplace_back(x, y);
    }

    sort(begin(drives), end(drives), [](const pii& a, const pii& b) {
        int buck1 = sgn(a.second - a.first);
        int buck2 = sgn(b.second - b.first);
        if (buck1 != buck2) {
            return buck1 < buck2;
        }

        if (buck1 == -1) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    });

    ll start = 0;
    ll cur = 0;
    ll need, after;
    for (const pii& p : drives) {
        tie(need, after) = p;
        if (need > cur) {
            int delta = need - cur;
            start += delta;
            cur += delta;
        }

        cur += after - need;
    }

    printf("%lld\n", start);

    return 0;
}
