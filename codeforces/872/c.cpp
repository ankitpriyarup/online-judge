#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    ll n;
    scanf("%d", &q);
    while (q-- > 0) {
        scanf("%lld", &n);
        ll on = n;

        if (n < 4) {
            printf("%d\n", -1);
            continue;
        }

        ll ans = 0LL;
        if (n % 2 == 1) {
            ++ans;
            n -= 9;
        }

        if (n < 0) {
            printf("%d\n", -1);
            continue;
        }

        n /= 2LL;
        if (n % 2 == 1) {
            ++ans;
            n -= 3;
        }

        if (n < 0) {
            printf("%d\n", -1);
            continue;
        }

        ans += (n / 2);
        printf("%lld\n", ans);

        // given 4x + 6y = n
        // maximize x + y
        //
        // 2x + 3y = n

        // comp = 4 6 9 16
        // 4 = 4
        // 5 = -1
        // 6 = 6
        // 7 = -1
        // 8 = 4 + 4
        // 9 = -1
        // 10 = 4 + 6
        // 11 = -1
        // 12 = 4 + 4 + 4
        // 13 = 4 + 9
        // 14 = 4 + 4 + 6
        // 15 = 6 + 9
    }

    return 0;
}
