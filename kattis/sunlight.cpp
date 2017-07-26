#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long double ld;

const int MAXN = 200005;
const ld PI = acos(-1);
const ld EPS = 1e-12L;

int n;
ld ans[MAXN];
bool flip = false;

struct tower {
    int x, h, i;

    bool operator<(const tower& other) const {
        return x < other.x;
    }
};

vector<tower> towers;

// value to add to answer of t2 if t1 is preceding it in hull
ld score(const tower& t1, const tower& t2) {
    if (t2.h >= t1.h) {
        return 6.0;
    }

    int hd = t1.h - t2.h;
    int xd = t2.x - t1.x;

    assert(hd > 0);
    assert(xd > 0);

    return 6.0 - (12.0L * atan(hd / (0.0L + xd)) / PI);
}

bool should_pop(const tower& t0, const tower& t1, const tower& t2) {
    int a = t1.x - t0.x;
    int b = t1.h - t0.h;

    int c = t2.x - t0.x;
    int d = t2.h - t0.h;

    assert(a >= 0);
    assert(c >= 0);

    return 1LL * a * d >= 1LL * b * c;
}

void hull() {
    vector<int> stk;
    ans[towers[0].i] += 6.0;
    ans[towers[1].i] += score(towers[0], towers[1]);

    stk.push_back(0);
    stk.push_back(1);
    for (int i = 2; i < n; ++i) {
        while (stk.size() >= 2 and should_pop(
                    towers[stk[stk.size() - 2]], towers[stk[stk.size() - 1]], towers[i])) {
            stk.pop_back();
        }

        ans[towers[i].i] += score(towers[stk.back()], towers[i]);

        stk.push_back(i);
    }
}

int main() {
    scanf("%d", &n);

    if (n == 1) {
        printf("12.0\n");
        return 0;
    }

    int x, h;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &h);
        towers.push_back({x, h, i});
        ans[i] = 0.0L;
    }

    sort(towers.begin(), towers.end());
    hull();

    for (int i = 0; i < n; ++i) {
        towers[i].x *= -1;
    }

    sort(towers.begin(), towers.end());
    hull();

    for (int i = 0; i < n; ++i) {
        printf("%.12Lf\n", ans[i]);
    }

    return 0;
}
