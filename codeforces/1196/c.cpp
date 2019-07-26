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
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while (q-- > 0) {
        int n;
        cin >> n;
        int minx = -1e5;
        int maxx = 1e5;
        int miny = -1e5;
        int maxy = 1e5;

        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;

            int f;

            cin >> f;
            if (f == 0) {
                minx = max(minx, x);
            }

            cin >> f;
            if (f == 0) {
                maxy = min(maxy, y);
            }

            cin >> f;
            if (f == 0) {
                maxx = min(maxx, x);
            }

            cin >> f;
            if (f == 0) {
                miny = max(miny, y);
            }
        }

        if (minx > maxx or miny > maxy) {
            cout << 0 << '\n';
        } else {
            cout << 1 << ' ' << minx << ' ' << miny << '\n';
        }
    }

    return 0;
}
