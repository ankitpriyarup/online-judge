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
using cd = complex<double>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double x, y;
    int r;
    constexpr double EPS = 1e-9;
    int tc = 1;
    while (scanf(" %lf %lf %d", &x, &y, &r) == 3) {
        cd c(x, y);
        cd z(0, 0);
        bool diverge = false;
        for (int i = 0; i <= r; ++i) {
            if (norm(z) >= 4.0 - EPS) {
                diverge = true;
                break;
            }

            z = z * z + c;
        }

        printf("Case %d: %s\n", tc++, diverge ? "OUT" : "IN");
    }
    
    return 0;
}
