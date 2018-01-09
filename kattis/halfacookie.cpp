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

    ld r, x, y;
    while (scanf("%Lf %Lf %Lf", &r, &x, &y) == 3) {
        ld d2 = x * x + y * y;
        if (d2 > r * r) {
            printf("miss\n");
            continue;
        }

        ld d = sqrt(d2);
        ld theta = acos(d / r);
        // pi * r * r * theta / 2 * pi
        // r * r * theta / 2
        ld total_area = r * r * theta;

        ld h = sqrt(r * r - d2);
        ld triangle = h * d;

        ld small = total_area - triangle;
        ld big = M_PI * r * r - small;

        printf("%.17Lf %.17Lf\n", big, small);
    }

    return 0;
}
