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
constexpr int LOGN = 31;
int f[MAXN];
int g[LOGN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x0, a, b, c, m, k;
    scanf(" %d %d %d %d %d %d", &x0, &a, &b, &c, &m, &k);
    for (int x = 0; x < m; ++x) {
        f[x] = (1LL * a * x * x) % m;
        f[x] = (1LL * f[x] + (1LL * b * x) % m) % m;
        f[x] = (0LL + f[x] + c) % m;
        g[0][x] = f[x];
    }

    for (int j = 0; j + 1 < LOGN; ++j) {
        for (int i = 0; i < m; ++i) {
            g[j + 1][i] = g[j][g[j][i]];
        }
    }

    int p = x0;
    for (int j = LOGN - 1; j >= 0; --j) {
        if (k & (1 << j)) {
            p %= m;
            p = g[j][p];
        }
    }

    printf("%d\n", p);

    return 0;
}
