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

constexpr int MAXN = (1 << 19) + 19;
int n;
int b[MAXN];
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &b[i]);
    }
    sort(b, b + n);
    reverse(b, b + n);
    int lg = 1;
    while ((1 << lg) < n)
        ++lg;

    ll ans = 0LL;
    int wins = lg;
    int sz = 0;
    int ptr = 0;
    while (ptr < n) {
        for (int i = 0; i < max(1, sz); ++i) {
            ans += 1LL * wins * b[ptr];
            if (sz)
                ans -= b[ptr];
            ++ptr;
        }

        if (sz) {
            sz = 2 * sz;
        } else {
            sz = 1;
        }
        --wins;
    }

    printf("%lld\n", ans);
    return 0;
}
