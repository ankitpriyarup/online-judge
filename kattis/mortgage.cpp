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

    int x, y, n;
    ld r;
    const ld EPS = 1e-9;
    while (scanf("%d %d %d %Lf", &x, &y, &n, &r) == 4) {
        if (x == 0) break;
        // make everything month based;
        n *= 12;
        r /= 1200.0;
        r += 1.0;

        // f^1(x) = x * r - y
        // f^2(x) = (x * r - y) * r - y
        // f^2(x) = x r^2 - y r - y
        // f^3(x) = x r^3 - y r^2 - yr - y
        // f^n(x) = x r^n - y * (r^n - 1) / (r - 1)

        /*
        double rem = x;
        for (int i = 0; rem > 0.0 and i < n; ++i)
            rem = rem * r - y;
        */
        if (abs(1.0L - r) <= EPS) {
            printf("%s\n", x - n * y <= EPS ? "YES" : "NO");
        } else {
            ld r2 = 1.0L * x * pow(r, n) - 1.0L * y * (pow(r, n) - 1.0L) / (r - 1.0L);
            printf("%s\n", r2 <= EPS ? "YES" : "NO");
        }
    }

    return 0;
}
