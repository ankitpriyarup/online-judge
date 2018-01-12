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

int dim;
ld a[1003], b[1003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &dim);
    for (int i = 0; i < dim; ++i) {
        scanf("%Lf", a + i);
    }

    ld res = 0;
    for (int i = 0; i < dim; ++i) {
        scanf("%Lf", b + i);
        ld d = a[i] - b[i];
        res += d * d;
    }

    res = sqrt(res);
    printf("%.17Lf\n", res);

    return 0;
}
