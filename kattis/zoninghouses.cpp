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
using pii = pair<ll, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
// constexpr int INF = 1e9 + 7;
int n, q;
ll x[MAXN], y[MAXN];

constexpr pii INF = {1e9 + 7, -1};

template <class T>
struct RMQ {
    vector<vector<T>> jmp;

    RMQ(const vector<T>& V) {
        int N = V.size();
        int on = 1, depth = 1;
        while (on < V.size()) on *= 2, depth++;
        jmp.assign(depth, V);
        for (int i = 0; i < depth - 1; ++i) {
            for (int j = 0; j < N; ++j)
                jmp[i + 1][j] = min(jmp[i][j], jmp[i][min(N - 1, j + (1 << i))]);
        }
    }
    // [a, b)
    T query(int a, int b) {
        if (b <= a) return INF;
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

ll without(RMQ<pii>& minxrmq, RMQ<pii>& minyrmq, RMQ<pii>& maxxrmq, RMQ<pii>& maxyrmq, int l, int r, int excluded) {
    pii minx = min(minxrmq.query(l, excluded), minxrmq.query(excluded + 1, r));
    pii miny = min(minyrmq.query(l, excluded), minyrmq.query(excluded + 1, r));
    pii maxx = min(maxxrmq.query(l, excluded), maxxrmq.query(excluded + 1, r));
    pii maxy = min(maxyrmq.query(l, excluded), maxyrmq.query(excluded + 1, r));

    ll dx = (-maxx.first - minx.first);
    ll dy = (-miny.first - maxy.first);
    return max(dx, dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &q);
    vector<pii> min_x;
    vector<pii> min_y;
    vector<pii> max_x;
    vector<pii> max_y;
    for (int i = 0; i < n; ++i) {
        scanf(" %lld %lld", x + i, y + i);
        min_x.emplace_back(x[i], i);
        min_y.emplace_back(y[i], i);

        max_x.emplace_back(-x[i], i);
        max_y.emplace_back(-y[i], i);
    }

    RMQ<pii> minxrmq(min_x);
    RMQ<pii> minyrmq(min_y);
    RMQ<pii> maxxrmq(max_x);
    RMQ<pii> maxyrmq(max_y);

    int l, r;
    while (q-- > 0) {
        scanf(" %d %d", &l, &r);
        assert(l < r);
        --l;
        pii minx1 = minxrmq.query(l, r);
        pii miny1 = minyrmq.query(l, r);
        pii maxx1 = maxxrmq.query(l, r);
        pii maxy1 = maxyrmq.query(l, r);

        /*
        printf("Bounds are x: [%lld, %lld], y: [%lld, %lld]\n", minx1.first, -maxx1.first, miny1.first, -maxy1.first);
        printf("Seconds are x: [%lld, %lld], y: [%lld, %lld]\n", minx2.first, -maxx2.first, miny2.first, -maxy2.first);
        */

        ll dx = -maxx1.first - minx1.first;
        ll dy = -maxy1.first - miny1.first;

        ll ans = max(dx, dy);

        ans = min(ans, without(minxrmq, minyrmq, maxxrmq, maxyrmq, l, r, minx1.second));
        ans = min(ans, without(minxrmq, minyrmq, maxxrmq, maxyrmq, l, r, miny1.second));
        ans = min(ans, without(minxrmq, minyrmq, maxxrmq, maxyrmq, l, r, maxx1.second));
        ans = min(ans, without(minxrmq, minyrmq, maxxrmq, maxyrmq, l, r, maxy1.second));

        printf("%lld\n", ans);
    }

    return 0;
}
