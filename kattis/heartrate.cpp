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

    int T;
    scanf("%d", &T);

    int b;
    ld p;
    while (T-- > 0) {
        scanf("%d %Lf", &b, &p);
        ld calc = 60.0L * b / p;

        // (b - 1) * t <= p
        ld min_t = p / (b - 1);
        ld max_t = p / (b + 1);
        printf("%.6Lf %.6Lf %.6Lf\n", 60.0 / min_t, calc, 60.0L / max_t);
    }

    return 0;
}
