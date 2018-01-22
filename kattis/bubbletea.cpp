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

constexpr int MAXN = 1003;
int n, m;
ll a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }

    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%lld", b + i);
    }

    ll min_cost = 1e18;
    int k;
    ll x;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        while (k-- > 0) {
            scanf("%lld", &x);
            min_cost = min(min_cost, a[i] + b[x]);
        }
    }

    scanf("%lld", &x);
    ll ans = x / min_cost;
    printf("%lld\n", max(0LL, ans - 1));

    return 0;
}
