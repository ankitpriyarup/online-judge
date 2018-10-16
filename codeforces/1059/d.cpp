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

using pt = pair<ld, ld>;

bool works(const vector<pt>& pts, ld rad) {
    ld max_l = -1e15;
    ld min_r = 1e15;
    for (const pt& p : pts) {
        ld x = p.first;
        ld y = p.second;
        if (y > rad + rad)
            return false;

        ld b = abs(y - rad);
        ld a = sqrt(rad * rad - b * b);
        max_l = max(max_l, x - a);
        min_r = min(min_r, x + a);
    }

    return max_l <= min_r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pt> pos, neg;
    int x, y;

    const ld EPS = 1e-6;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (y > 0)
            pos.push_back({x, y});
        else
            neg.push_back({x, y});
    }

    if (!pos.empty() and !neg.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    if (pos.empty()) {
        for (const pt& p : neg) {
            pos.push_back({p.first, -p.second});
        }
    }

    ld lo = 0.0;
    ld hi = 1e16;
    for (int iter = 0; iter < 300; ++iter) {
        ld mid = (lo + hi) / 2;
        if (works(pos, mid))
            hi = mid;
        else
            lo = mid;
    }

    cout << fixed << setprecision(10) << ((lo + hi) / 2.0) << '\n';

    return 0;
}
