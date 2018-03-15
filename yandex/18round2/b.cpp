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

constexpr int MAXN = 100005;
int n, m;
ll a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    ll asum = 0;
    ll amax = -1;
    int first, last;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
        asum += a[i];
        if (a[i] > amax) {
            first = last = i;
            amax = a[i];
        } else if (a[i] == amax) {
            last = i;
        }
    }

    ll bsum = 0;
    ll bmax = -1;
    for (int i = 0; i < m; ++i) {
        scanf("%lld", b + i);

        bsum += b[i];
        bmax = max(bmax, b[i]);
    }
    
    // return 10^9 * asum + bsum
    // maximize asum, then bsum
    // asum = sum a + best way to distribute m - 1 values over a
    // go to the largest thing in a and move only right there
    //
    // maximize b given how you maximized a
    // first * b[0] + bmax * (last - first + 1) + (n - last) * b[m - 1]
    ll apart = asum + (m - 1LL) * amax;
    ll bpart = bsum + b[0] * first + bmax * (last - first) + (n - last - 1) * b[m - 1];

    printf("%lld\n", apart * static_cast<ll>(1e9) + bpart); 

    return 0;
}
