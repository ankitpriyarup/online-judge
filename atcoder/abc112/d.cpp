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

int n, m;

bool works(int d) {
    return m % d == 0 and m / d >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);

    int ans = 1;
    for (int d = 1; d * d <= m; ++d) {
        if (m % d == 0 and works(d))
            ans = max(ans, d);
        if (m % d == 0 and works(m / d))
            ans = max(ans, m / d);
    }

    printf("%d\n", ans);

    return 0;
}
