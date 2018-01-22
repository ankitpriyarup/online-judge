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
int n, m, k;

// can fit square house of side length s in hole with radius r
// if (s/2) * sqrt(2) < r
int a[MAXN], b[MAXN], c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < m; ++i)
        scanf("%d", b + i);
    for (int i = 0; i < k; ++i)
        scanf("%d", c + i);

    sort(a, a + n);
    sort(b, b + m);
    sort(c, c + k);

    int bi = 0;
    int ci = 0;
    int res = 0;

    ld s2 = sqrt(2) / 2.0;
    for (int i = 0; i < n; ++i) {
        if (bi < m and b[bi] < a[i]) {
            ++res;
            ++bi;
        } else if (ci < k and s2 * c[ci] < a[i]) {
            ++res;
            ++ci;
        }
    }

    printf("%d\n", res);

    return 0;
}
