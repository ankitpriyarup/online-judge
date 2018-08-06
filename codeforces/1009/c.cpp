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

    int n, m;
    scanf(" %d %d", &n, &m);
    ll x, d;
    // 0 + 1 + 2 + ... n - 1
    ll d1 = 1LL * n * (n - 1) / 2LL;
    ll d2 = (n % 2 == 0 ? (n / 2LL) : 0) + 1LL * ((n - 1) / 2) * ((n - 1) / 2 + 1);

    ll sum = 0LL;

    for (int i = 0; i < m; ++i) {
        scanf(" %lld %lld", &x, &d);
        sum += 1LL * n * x;
        sum += max(d1 * d, d2 * d);
    }

    printf("%.9Lf\n", static_cast<long double>(sum) / n);
    
    return 0;
}
