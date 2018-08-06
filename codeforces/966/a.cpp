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
#define x1 asdhguasdhg
#define y1 ioweytoiewas

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXC = 100005;
constexpr ll INF = 1e18;
ll n, m; 
int cl, cc;
ll v;
ll stairs[MAXC];
ll elev[MAXC];

ll x1, x2, y1, y2;
ll solve_stair(int id) {
    if (id < 0 or id >= cl)
        return INF;

    return abs(y2 - y1) + abs(x1 - stairs[id]) + abs(x2 - stairs[id]);
}

ll solve_elev(int id) {
    if (id < 0 or id >= cc)
        return INF;

    ll dy = (abs(y2 - y1) + v - 1) / v;
    return dy + abs(x1 - elev[id]) + abs(x2 - elev[id]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %lld %lld %d %d %lld", &n, &m, &cl, &cc, &v);
    for (int i = 0; i < cl; ++i) {
        scanf(" %lld", &stairs[i]);
    }
    for (int i = 0; i < cc; ++i) {
        scanf(" %lld", &elev[i]);
    }

    int q;
    scanf(" %d", &q);
    while (q-- > 0) {
        scanf(" %lld %lld %lld %lld", &y1, &x1, &y2, &x2);
        ll ans = 1e18;

        if (y1 == y2) {
            ans = abs(x1 - x2);
        }

        // stairs before
        int s = lower_bound(stairs, stairs + cl, x1) - stairs;
        ans = min(ans, solve_stair(s));
        ans = min(ans, solve_stair(s - 1));
        s = lower_bound(stairs, stairs + cl, x2) - stairs;
        ans = min(ans, solve_stair(s));
        ans = min(ans, solve_stair(s - 1));

        int t = lower_bound(elev, elev + cc, x1) - elev;
        ans = min(ans, solve_elev(t));
        ans = min(ans, solve_elev(t - 1));
        t = lower_bound(elev, elev + cc, x2) - elev;
        ans = min(ans, solve_elev(t));
        ans = min(ans, solve_elev(t - 1));

        printf("%lld\n", ans);
    }

    return 0;
}
