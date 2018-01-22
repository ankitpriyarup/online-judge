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

constexpr int MAXN = 102;
int n, l;
int d[MAXN], r[MAXN], g[MAXN], a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", d + i, r + i, g + i);
        a[i] = i;
    }

    sort(a, a + n, [](const int& x, const int& y) {
        return d[x] < d[y];
    });

    int t = 0;
    int p = 0;

    for (int i = 0; i < n; ++i) {
        // get to d[a[i]]
        t += d[a[i]] - p;
        p = d[a[i]];
        int mod = r[a[i]] + g[a[i]];
        if (t % mod < r[a[i]]) {
            int d = r[a[i]] - (t % mod);
            t += d;
        }
    }

    t += l - p;

    printf("%d\n", t);

    return 0;
}
