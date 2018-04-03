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

struct seg {
    ll x0, x1, y;
};

struct event {
    ll dx, dy, delta;

    bool operator<(const event& other) const {
        ll v1 = 1LL * dy * other.dx;
        ll v2 = 1LL * other.dy * dx;

        return tie(v1, other.delta) < tie(v2, delta);
    }
};

ll gcd(ll a, ll b) {
    if (a < 0) return gcd(-a, b);
    if (b < 0) return gcd(a, -b);
    return b ? gcd(b, a % b) : a;
}

void make_slope(ll& dx, ll& dy, ll ddx, ll ddy) {
    dx = ddx;
    dy = ddy;
    ll g = gcd(dx, dy);
    dx /= g;
    dy /= g;
    if (dy < 0 or (dy == 0 and dx < 0)) {
        dx *= -1;
        dy *= -1;
    }
}

ll solve(const vector<seg>& segs, ll x, ll y, ll score) {
    vector<event> events;
    ll dx, dy;
    for (const seg& p : segs) {
        if (p.y == y)
            continue;

        int seg_score = p.x1 - p.x0;
        make_slope(dx, dy, x - p.x1, y - p.y);
        event a{dx, dy, seg_score};

        make_slope(dx, dy, x - p.x0, y - p.y);
        event b{dx, dy, seg_score};

        if (a < b) {
            b.delta *= -1;
        } else {
            a.delta *= -1;
        }

        events.push_back(a);
        events.push_back(b);
    }

    sort(begin(events), end(events));
    ll res = score;
    ll cur_score = score;

    // printf("Starting sweep from %lld %lld\n", x, y);
    for (auto& evt : events) {
        // printf("EVENT: (dx, dy): (%lld, %lld), score: %lld\n", evt.dx, evt.dy, evt.delta);
        cur_score += 1LL * evt.delta;
        res = max(res, cur_score);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    ll x0, x1, y;
    vector<seg> segs;
    for (int i = 0; i < n; ++i) {
        scanf(" %lld %lld %lld", &x0, &x1, &y);
        if (x0 > x1)
            swap(x0, x1);

        segs.push_back({x0, x1, y});
    }

    ll ans = 0;
    for (const seg& p : segs) {
        ans = max(ans, solve(segs, p.x0, p.y, p.x1 - p.x0));
        ans = max(ans, solve(segs, p.x1, p.y, p.x1 - p.x0));
    }

    printf("%lld\n", ans);

    return 0;
}
