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

struct rect {
    int x1, y1, x2, y2;

    rect(): x1(0), y1(0), x2(0), y2(0) {}
    rect(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}

    rect intersect(const rect& o) const {
        return {max(x1, o.x1), max(y1, o.y1), min(x2, o.x2), min(y2, o.y2)};
    }

    bool empty() const {
        return x1 > x2 or y1 > y2;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    vector<rect> rects(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d %d %d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);
    }

    vector<rect> pref(begin(rects), end(rects));
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1].intersect(rects[i]);
    }

    vector<rect> suff(begin(rects), end(rects));
    for (int i = n - 2; i >= 0; --i) {
        suff[i] = suff[i + 1].intersect(rects[i]);
    }

    if (!pref[n - 2].empty()) {
        printf("%d %d\n", pref[n - 2].x1, pref[n - 2].y1);
        return 0;
    }
    if (!suff[1].empty()) {
        printf("%d %d\n", suff[1].x1, suff[1].y1);
        return 0;
    }

    for (int i = 1; i + 1 < n; ++i) {
        rect cur = pref[i - 1].intersect(suff[i + 1]);
        if (!cur.empty()) {
            printf("%d %d\n", cur.x1, cur.y1);
            return 0;
        }
    }

    return 0;
}
