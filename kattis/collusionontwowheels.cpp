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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);

    int x, y;
    vector<pii> pts;;
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &x, &y);
        // rotate by 45 degrees
        pts.emplace_back(x - y, x + y);

        // printf("PT %d, %d\n", x - y, x + y);
    }

    // first point is left-most
    // need to try all possible y
    sort(begin(pts), end(pts));

    vector<int> all_y;
    for (int i = 0; i < n; ++i) {
        if (pts[i].second <= pts[0].second) {
            all_y.push_back(pts[i].second);
        }
    }

    sort(begin(all_y), end(all_y));
    all_y.erase(unique(begin(all_y), end(all_y)), end(all_y));

    int start_x = pts[0].first;

    constexpr int INF = 1e8;

    int lo = -1;
    int hi = INF;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;

        bool works = false;
        for (int start_y : all_y) {

            int minx = INF;
            int maxx = -INF;
            int miny = INF;
            int maxy = -INF;
            for (int i = 0; i < n; ++i) {
                tie(x, y) = pts[i];
                if (start_x <= x and x <= start_x + mid and start_y <= y and y <= start_y + mid) {
                    // in first box
                } else {
                    minx = min(minx, x);
                    maxx = max(maxx, x);
                    miny = min(miny, y);
                    maxy = max(maxy, y);
                }
            }

            works |= (maxx - minx) <= mid and (maxy - miny) <= mid;
        }

        if (works) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%d\n", hi);
    
    return 0;
}
