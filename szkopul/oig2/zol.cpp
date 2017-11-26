#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

constexpr int MAXN = 2e5 + 5;
constexpr int MOD = 10000000;
int n;
ll a[MAXN];
ll fact[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        fact[i] = (1LL * i * fact[i - 1]) % MOD;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }

    sort(a, a + n);
    ll last = -1;
    int ct = 0;
    ll ans = 1;
    bool pad = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] != last) {
            ans = ans * fact[ct];
            if (ans > 10000) {
                pad = true;
            }
            ans %= MOD;
            ct = 0;
        }

        ++ct;
        last = a[i];
    }

    ans = ans * fact[ct];
    if (a[0] != a[n - 1]) {
        ans = 2LL * ans;
    }

    if (ans > 10000) pad = true;
    ans %= 10000;

    if (!pad) {
        printf("%lld\n", ans);
    } else {
        if (ans < 10) {
            printf("000");
        } else if (ans < 100) {
            printf("00");
        } else if (ans < 1000) {
            printf("0");
        }

        printf("%lld\n", ans % 10000);
    }

    return 0;
}
