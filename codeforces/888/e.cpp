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

constexpr int MAXN = 36;
constexpr int HALF = 18;
int n, m;
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
        a[i] %= m;
        // printf("%lld ", a[i]);
    }
    // printf("\n");

    ll ans = 0LL;
    set<ll> in_first;
    int first = min(n, HALF);
    for (int mask = 0; mask < (1 << first); ++mask) {
        ll sum = 0LL;
        for (int i = 0; i < first; ++i) {
            if (mask & (1 << i)) {
                sum += a[i];
                sum %= m;
            }
        }

        in_first.insert(sum);
        ans = max(ans, sum);
    }

    if (n <= HALF) {
        printf("%lld\n", ans);
        return 0;
    }

    set<ll> in_second;
    int second = n - first;
    for (int mask = 0; mask < (1 << second); ++mask) {
        ll sum = 0LL;
        for (int i = first; i < n; ++i) {
            if (mask & (1 << (i - first))) {
                sum += a[i];
                sum %= m;
            }
        }

        in_second.insert(sum);
        ans = max(ans, sum);
        // find the largest x in the first half s.t. x < m - sum
        auto it = in_first.lower_bound(m - sum);
        while (it != begin(in_first) and *it >= m - sum)
            it = prev(it);

        ans = max(ans, sum + *it);
    }

    printf("%lld\n", ans);

    return 0;
}
