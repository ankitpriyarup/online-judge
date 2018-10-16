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

namespace uf {
    constexpr int MAXN = 1e6;
    int par[MAXN];
    int id[MAXN];
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            id[i] = i;
        }
    }

    int find(int x) {
        return par[x] = (x == par[x] ? x : find(par[x]));
    }

    void merge(int x, int y) {
        int xr = uf::find(x);
        int yr = uf::find(y);
        if (xr == yr) return;

        if (rand() % 2) {
            par[xr] = yr;
            id[yr] = min(id[xr], id[yr]);
        } else {
            par[yr] = xr;
            id[xr] = min(id[xr], id[yr]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, r, k, x, a, b;
    scanf(" %d %d %d %d %d %d", &n, &r, &k, &x, &a, &b);
    vector<int> rem(n, k);

    uf::init(n);

    int ans = 0;
    bool bad0 = false;
    for (int i = 0; i < r; ++i) {
        x = (1LL * x * a + b) % n;
        int g = uf::id[uf::find(x)];
        if (g == 0 and bad0) {
            printf("OVERFLOW\n");
            return 0;
        }
        ans = (1LL * 53 * ans + g) % 199933;
        if (--rem[g] == 0) {
            if (g == 0) {
                bad0 = true;
            } else {
                uf::merge(g, g - 1);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
