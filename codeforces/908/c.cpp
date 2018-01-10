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

constexpr int MAXN = 1003;
int r, n;
int x[MAXN];
ld y[MAXN];

ld compute(int a, int b) {
    int dx = abs(x[a] - x[b]);
    if (dx > 2 * r)
        return 0.0L;

    return y[a] + sqrt(4.0L * r * r - dx * dx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; ++i) {
        scanf("%d", x + i);
        y[i] = r;
        for (int j = 0; j < i; ++j) {
            y[i] = max(y[i], compute(j, i));
        }
        printf("%.17Lf ", y[i]);
    }
    printf("\n");
    
    return 0;
}
