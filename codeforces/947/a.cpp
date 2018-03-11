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

constexpr int MAXN = 1e6 + 6;
bool done[MAXN];
int sieve[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve[0] = sieve[1] = 1;
    for (int i = 2; i < MAXN; i += 2)
        sieve[i] = 2;

    for (int i = 3; i < MAXN; i += 2) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            for (ll j = 1LL *i * i; j < MAXN; j += 2 * i) {
                sieve[j] = i;
            }
        }
    }

    int x;
    scanf("%d", &x);
    int xmin = x;

    int n = x;
    while (n > 1) {
        int d = sieve[n];
        if (d == x) break;
        xmin = min(xmin, x - d + 1);
        while (n % d == 0)
            n /= d;
    }

    // printf("xmin: %d\n", xmin);

    int ans = x;
    for (int i = xmin; i < x; ++i) {
        n = i;
        while (n > 1) {
            int d = sieve[n];
            if (d == i) break;
            ans = min(ans, i - d + 1);
            // printf("i: %d, d: %d res: %d\n", i, d, i - d + 1);
            while (n % d == 0)
                n /= d;
        }
    }

    printf("%d\n", min(xmin, ans));

    return 0;
}
