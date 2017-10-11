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

ll dx[] = {0, 1118, 1680, 2018};
ll dy[] = {2018, 1680, 1118, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    ll x, y;
    ll ans = 0LL;
    set<pair<ll, ll> > pts;

    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &x, &y);
        set<pair<ll, ll> > found;

        for (int b1 = -1; b1 <= 1; b1 += 2) {
            for (int b2 = -1; b2 <= 1; b2 += 2) {
                for (int d = 0; d < 4; ++d) {
                    ll nx = x + b1 * dx[d];
                    ll ny = y + b2 * dy[d];
                    if (pts.find({nx, ny}) != pts.end()) {
                        found.insert({nx, ny});
                    }
                }
            }
        }
        ans += found.size();
        pts.insert({x, y});
    }

    printf("%lld\n", ans);

    return 0;
}
