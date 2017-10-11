#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXP = 505;
int s, p;
int x[MAXP], y[MAXP];

namespace uf {
    int ids[MAXP];

    void init() {
        for (int i = 0; i < MAXP; ++i) {
            ids[i] = i;
        }
    }

    int find(int x) {
        return ids[x] = (x == ids[x] ? x : find(ids[x]));
    }

    bool join(int x, int y) {
        int xr = find(x);
        int yr = find(y);

        if (xr == yr) {
            return false;
        }

        if (rand() % 2) {
            ids[xr] = yr;
        } else {
            ids[yr] = xr;
        }

        return true;
    }
}

void read() {
    scanf("%d %d", &s, &p);
    for (int i = 0; i < p; ++i) {
        scanf("%d %d", x + i, y + i);
    }
}

inline ll dist(int i, int j) {
    ll xd = x[i] - x[j];
    ll yd = y[i] - y[j];

    return xd * xd + yd * yd;
}

bool works(ll weight) {
    uf::init();

    int comps = p;
    for (int i = 0; comps > s and i < p; ++i) {
        for (int j = i + 1; comps > s and j < p; ++j) {
            if (dist(i, j) <= weight)
                comps -= uf::join(i, j);
        }
    }

    return comps <= s;
}

void solve() {
    ll lo = 0;
    ll hi = 1e18;
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2LL;
        if (works(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%.2f\n", sqrt(hi));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        read();
        solve();
    }
    
    return 0;
}
