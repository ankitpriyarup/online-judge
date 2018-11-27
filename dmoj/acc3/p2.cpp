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

constexpr int MAXN = 1000006;
int n;
int xs[MAXN], ys[MAXN], orig[MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // distance is max(|x_i - x|, |y_i - y|)
    // I'd like it to be |x_i - x| + |y_i - y|
    //
    // Rotate by 45 degrees?
    //
    // x' = x + y
    // y' = x - y
    //
    // x = (x' + y') / 2
    // y = (x' - y') / 2
    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", xs + i, ys + i);
        orig[i][0] = xs[i];
        orig[i][1] = ys[i];

        xs[i] = orig[i][0] + orig[i][1];
        ys[i] = orig[i][0] - orig[i][1];
    }

    sort(xs, xs + n);
    sort(ys, ys + n);

    int tx = xs[n >> 1];
    int ty = ys[n >> 1];

    int x = (tx + ty) >> 1;
    int y = (tx - ty) >> 1;

    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        ans += max(abs(orig[i][0] - x), abs(orig[i][1] - y));
    }

    printf("%lld\n", ans);
    
    return 0;
}
