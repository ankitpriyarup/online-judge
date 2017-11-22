#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

constexpr int MAXN = 30004;
int n;
int a[MAXN];

namespace uf {
    int par[MAXN];
    void init() {
        for (int i = 0; i < MAXN; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        return par[x] = (x == par[x] ? x : find(par[x]));
    }

    bool merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);

        if (xr == yr) return false;
        par[xr] = yr;
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    uf::init();
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        ans -= uf::merge(i, a[i]);
    }

    printf("%d\n", ans);

    return 0;
}
