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
using endpoint = pair<pair<ld, ld>, ll>;

constexpr int MAXN = 102;
int n, step;
vector<endpoint> pts;

ld dist(const vector<endpoint>& v) {
    ld ans = 0.0L;
    for (int i = 1; i < v.size(); ++i) {
        ld xd = v[i].first.first - v[i - 1].first.first;
        ld yd = v[i].first.second - v[i - 1].first.second;

        ans += sqrt(xd * xd + yd * yd);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &step);

    ll x, y, t;
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &x, &y, &t);
        pts.push_back({{x, y}, t});
    }

    int ptr = 0;
    vector<endpoint> gps;
    for (int time = 0; time < pts[n - 1].second; time += step) {
        while (ptr < n - 1 and !(pts[ptr].second <= time and time < pts[ptr + 1].second)) {
            ++ptr;
        }

        ld frac = (1.0L * time - pts[ptr].second) / (1.0L * pts[ptr + 1].second - pts[ptr].second);
        ld nx = pts[ptr].first.first + frac * (pts[ptr + 1].first.first - pts[ptr].first.first);
        ld ny = pts[ptr].first.second + frac * (pts[ptr + 1].first.second - pts[ptr].first.second);

        gps.push_back({{nx, ny}, time});
    }

    gps.push_back(pts[n - 1]);

    ld d1 = dist(pts);
    ld d2 = dist(gps);

    ld diff = d1 - d2;
    ld pct = diff / d1;

    printf("%.12Lf\n", 100.0L * pct);

    return 0;
}
