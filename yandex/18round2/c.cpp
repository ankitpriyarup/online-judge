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
int n, m, ds, cs, da, ca;
int h[MAXN];
int hh[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d %d %d %d", &n, &m, &ds, &cs, &da, &ca);
    for (int i = 0; i < n; ++i) {
        scanf("%d", h + i);
    }

    int ans = 0;
    for (int all = 0; all <= m; ++all) {
        int curm = m - all * ca;
        if (curm < 0) break;

        for (int i = 0; i < n; ++i) {
            hh[i] = h[i] - da * all;
        }

        sort(hh, hh + n);
        int ptr = 0;

        while (ptr < n and curm >= 0) {
            if (hh[ptr] <= 0) {
                ++ptr;
            } else {
                int casts = (hh[ptr] + ds - 1) / ds;
                if (casts * cs <= curm) {
                    curm -= casts * cs;
                    ++ptr;
                } else {
                    break;
                }
            }
        }

        ans = max(ans, ptr);
    }

    printf("%d\n", ans);

    return 0;
}
