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

    int x, y;
    double z;
    scanf(" %d %d %lf", &x, &y, &z);
    int gap = 60 * (y - x);
    double tri = (gap - z) * (gap - z);
    double ans = gap * gap - tri;

    printf("%.9lf\n", ans / gap / gap);

    return 0;
}
