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
bool done[MAXN][MAXN];
ld dp[MAXN][MAXN];

ld solve(int w, int b) {
    if (w == 0) return 0.0L;
    if (w == 1 and b == 1) return 0.5L;
    if (w > 0 and b == 0) return 1.0L;
    if (done[w][b]) return dp[w][b];

    ld ret = 0.0L;
    ld den = w + b;
    // princess draws white mouse
    ret += w / den;

    // princess draws black, dragon draws black and scares white
    if (w >= 1 and b >= 2)
        ret += b / den * (b - 1) / (den - 1) * w / (den - 2) * solve(w - 1, b - 2);

    // princess draws black, dragon draws black and scares black
    if (b >= 3)
        ret += b / den * (b - 1) / (den - 1) * (b - 2) / (den - 2) * solve(w, b - 3);

    done[w][b] = true;
    return dp[w][b] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int w, b;
    scanf("%d %d", &w, &b);

    memset(done, 0, sizeof(done));
    printf("%.17Lf\n", solve(w, b));

    return 0;
}
