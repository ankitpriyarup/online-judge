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

constexpr ld g = 9.81;

bool solve() {
    ld v0, theta, x, h1, h2;
    scanf("%Lf %Lf %Lf %Lf %Lf", &v0, &theta, &x, &h1, &h2);

    theta = M_PI * theta / 180.0;

    ld t = x / v0 / cos(theta);
    ld y = v0 * t * sin(theta) - 0.5 * g * t * t;

    return y >= h1 + 1.0 and y <= h2 - 1.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        printf("%s\n", solve() ? "Safe" : "Not Safe");
    }
    
    return 0;
}
