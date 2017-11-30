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
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 1003;
int x[MAXN], y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", x + i, y + i);
        }
        ll area = 1LL * x[n - 1] * y[0] - 1LL * x[0] * y[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            area += 1LL * x[i] * y[i + 1] - 1LL * x[i + 1] * y[i];
        }

        if (area < 0) {
            printf("CW ");
            area = -area;
        } else {
            printf("CCW ");
        }

        if (area & 1) {
            printf("%lld.5\n", area / 2);
        } else {
            printf("%lld.0\n", area / 2);
        }
    }
    
    return 0;
}
