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

constexpr int MAXN = 200005;
constexpr ll MAXD = 1e10;
int n;
ll a[MAXN];

bool has(ll x) {
    int idx = lower_bound(a, a + n, x) - a;
    return idx >= 0 and idx < n and a[idx] == x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &a[i]);
    }
    sort(a, a + n);
    
    ll bestx = 0;
    ll besty = 0;
    for (ll d = 1; d < MAXD; d <<= 1LL) {
        for (int i = 0; i < n; ++i) {
            bool haslo = has(a[i] - d);
            bool hashi = has(a[i] + d);
            if (haslo and hashi) {
                printf("3\n");
                printf("%lld %lld %lld\n", a[i] - d, a[i], a[i] + d);
                return 0;
            }

            if (haslo) {
                bestx = a[i] - d;
                besty = a[i];
            }
            if (hashi) {
                bestx = a[i] + d;
                besty = a[i];
            }
        }
    }
    if (bestx != besty) {
        printf("2\n");
        printf("%lld %lld\n", bestx, besty);
    } else {
        printf("1\n");
        printf("%lld\n", a[0]);
    }

    return 0;
}
