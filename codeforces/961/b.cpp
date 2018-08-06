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
int n, k;
int a[MAXN], t[MAXN];
ll p[MAXN], q[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);

    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        p[i] = p[i - 1] + a[i];
    }

    q[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i]);
        q[i] = q[i - 1] + (t[i] ? a[i] : 0);
    }

    ll ans = 0LL;
    for (int i = 1; i + k <= n + 1; ++i) {
        ll score = q[i - 1] + (p[i + k - 1] - p[i - 1]) + (q[n] - q[i + k - 1]);
        ans = max(ans, score);
    }

    printf("%lld\n", ans);

    return 0;
}
