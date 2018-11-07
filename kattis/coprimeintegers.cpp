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

constexpr int MAXN = 10000000;
bool square[MAXN + 1];
int divs[MAXN + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c, d;
    scanf(" %d %d %d %d", &a, &b, &c, &d);
    ll ans = 1LL * (b - a + 1) * (d - c + 1);
    for (int i = 2; i <= max(b, d); ++i) {
        if (square[i]) continue;
        if (divs[i] == 0) {
            // i is prime
            for (ll j = 1LL * i * i; j <= MAXN; j += i * i) {
                square[j] = true;
            }

            for (int j = i; j <= MAXN; j += i) {
                divs[j] += 1;
            }
        }

        int v1 = b / i - (a - 1) / i;
        int v2 = d / i - (c - 1) / i;
        int sgn = divs[i] % 2 == 1 ? -1 : 1;
        ans += 1LL * sgn * v1 * v2;

        // printf("using var %d %d sign %d change %lld\n", i, divs[i], sgn, 1LL * v1 * v2);
    }

    printf("%lld\n", ans);
    
    return 0;
}
