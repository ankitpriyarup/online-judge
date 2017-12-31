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

constexpr int MAXN = 2003;
int n;
ll d;
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %lld", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }

    ll ans = 0LL;
    for (int i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1]) {
            ll diff = (a[i - 1] - a[i]);
            ll v = diff / d;

            while (v * d <= diff) {
                ++v;
            }

            ans += v;
            a[i] += v * d;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
