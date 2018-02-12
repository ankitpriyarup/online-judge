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

constexpr int MAXN = 55;
int n;
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }

    sort(a, a + n);
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        total += a[i];
    }

    ll ans1 = total / 2;
    ll ans2 = total - a[n - 1];

    if (2 * min(ans1, ans2) == total) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
