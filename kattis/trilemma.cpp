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

int x[3], y[3];

void solve() {
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }

    // make the first point 0 0
    for (int i = 1; i < 3; ++i) {
        x[i] -= x[0];
        y[i] -= y[0];
    }

    // figure out area. Cross product.
    int area = x[1] * y[2] - x[2] * y[1];
    if (area == 0) {
        cout << "not a triangle\n";
        return;
    }

    int dx = x[2] - x[1];
    int dy = y[2] - y[1];

    // check squared lengths for accuracy
    int l1 = x[1] * x[1] + y[1] * y[1];
    int l2 = x[2] * x[2] + y[2] * y[2];
    int l3 = dx * dx + dy * dy;
    if (l1 == l2 or l2 == l3 or l1 == l3) {
        cout << "isosceles ";
    } else {
        cout << "scalene ";
    }


    // check max angle
    // dot product is 0 if angle == 90, negative if angle > 90
    int minDot = 1e6;
    // base (0, 0)
    minDot = min(minDot, x[1] * x[2] + y[1] * y[2]);

    // base (x[1], y[1])
    minDot = min(minDot, -x[1] * (x[2] - x[1]) + -y[1] * (y[2] - y[1]));

    // base (x[2], y[2])
    minDot = min(minDot, -x[2] * (x[1] - x[2]) + -y[2] * (y[1] - y[2]));
    if (minDot == 0) {
        cout << "right ";
    } else if (minDot < 0) {
        cout << "obtuse ";
    } else {
        cout << "acute ";
    }

    cout << "triangle\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    int tc = 1;
    while (T-- > 0) {
        cout << "Case #" << tc++ << ": ";
        solve();
    }
    
    return 0;
}
