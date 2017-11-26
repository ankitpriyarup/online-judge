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

constexpr int MAXN = 100005;
int n;
ll k;
ll p[MAXN];
int verts[MAXN][25];
ll max_dist[MAXN];
int inds[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %lld", &n, &k);
    int m;
    for (int i = 0; i < n; ++i) {
        scanf("%d %lld", &m, p + i);
        max_dist[i] = 0;
        for (int j = 0; j < 2 * m; j += 2) {
            scanf("%d %d", &verts[i][j], &verts[i][j + 1]);
            max_dist[i] = max(max_dist[i], 1LL * verts[i][j] * verts[i][j] + 1LL * verts[i][j + 1] * verts[i][j + 1]);
        }
        inds[i] = i;
    }

    sort(inds, inds + n, [&](const int& a, const int& b) {
        return max_dist[a] == max_dist[b] ? a < b : max_dist[a] < max_dist[b];
    });

    ll ans = 0LL;
    ll profit = 0;
    for (int qq = 0; qq < n; ++qq) {
        int i = inds[qq];
        // find the smallest multiple of k such that k * k * x * x >= s
        ll x = (ll) sqrt(max_dist[i] / k / k);
        // printf("Max dist: %lld\n", max_dist[i]);
        while (k * k * x * x < max_dist[i])
            ++x;

        // printf("%lld units high for radius of %lld\n", x, k * x);
        profit += p[i];
        ll cost = -x * (x - 1) / 2;
        // printf("Construction: %lld, profit: %lld\n", cost, profit);
        ans = max(ans, cost + profit);
    }

    printf("%lld\n", ans);

    return 0;
}
