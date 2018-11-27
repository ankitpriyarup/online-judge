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

constexpr int MAXN = 1000060;
int n;
int a[MAXN];
int ct[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k;
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &a[i]);
    }

    int used = 0;
    int j = 0;
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        if (ct[a[i]]++ == 0)
            ++used;

        while (j < i and (used > k or (used == k and ct[a[j]] > 1))) {
            if (--ct[a[j]] == 0)
                --used;
            ++j;
        }

        // fprintf(stderr, "[%d %d] %d\n", i, j, used);
        if (used >= k)
            ans += j + 1;
    }

    printf("%lld\n", ans);

    return 0;
}
