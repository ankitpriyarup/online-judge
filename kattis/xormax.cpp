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

constexpr int MAXN = 100005;
int n;
ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &a[i]);
    }

    int row = 0;
    for (ll j = 62; j >= 0; --j) {
        ll p = (1LL << j);
        int pvt = row;

        for (int i = row + 1; i < n; ++i) {
            if (a[i] & p) {
                pvt = i;
                break;
            }
        }

        if ((a[pvt] & p) == 0) {
            continue;
        }

        swap(a[row], a[pvt]);

        for (int i = row + 1; i < n; ++i) {
            if (a[i] & p) {
                a[i] ^= a[row];
            }
        }

        ++row;
    }

    for (int row = n - 1; row >= 0; --row) {
        if (a[row] == 0) continue;
        ll p = 1LL;
        while (p < a[row])
            p <<= 1LL;
        if (p > a[row])
            p >>= 1LL;
        for (int i = 0; i < row; ++i) {
            if (a[i] & p)
                a[i] ^= a[row];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans ^= a[i];
    }

    printf("%lld\n", ans);

    return 0;
}
