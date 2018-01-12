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
int n, m;
ll k, a[MAXN];

bool works(ll target) {
    ll delta = 0;
    queue<pair<int, ll> > q;
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        if (!q.empty() and q.front().first == i) {
            delta -= q.front().second;
            q.pop();
        }

        if (a[i] + delta < target) {
            ll d = target - a[i] - delta;
            delta += d;
            total += d;
            q.push({i + m, d});
        }
    }

    return total <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %lld", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    ll lo = 0;
    ll hi;
    if (m == 1 or k == 1)
        hi = 1e9 + 7;
    else
        hi = 1e18;

    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (works(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%lld\n", lo);
    
    return 0;
}
