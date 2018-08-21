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
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &a[n + i]);
    }
    ll ans = 0LL;

    for (int i = n - 1; i > 0; --i) {
        int x = a[2 * i];
        int y = a[2 * i + 1];
        a[i] = max(x, y);
        ans += abs(x - y);
    }

    printf("%lld\n", ans);
    return 0;
}
