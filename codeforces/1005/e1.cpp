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

constexpr int MAXN = 200005;
int n, x;
int p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &x);
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &p[i]);
    }

    // if sum is 3, need at least 3 x
    // if sum is 4, need at least 4 x
    // want to count number of pairs i, j where
    // x_ct[j] - x_ct[i] >= pref[j] - pref[i] AND pref[j] - pref[i] >= 0 AND x_ct[j] - x_ct[i] > 0

    map<int, int> freq;
    ll ans = 0;
    bool seen_x = false;
    ll cur = 0;
    ++freq[cur];
    // printf("Ending at %d with cur %d\n", 0, 0);
    for (int i = 1; i <= n; ++i) {
        seen_x |= (p[i] == x);
        cur += p[i] > x ? 1 : p[i] < x ? -1 : 0;

        if (seen_x) {
            // printf("Adding freq[%d] = %d and freq[%d] = %d\n", cur, freq[cur], cur - 1, freq[cur - 1]);
            ans += freq[cur];
            ans += freq[cur - 1];
        } else {
            // printf("Ending at %d with cur %d\n", i, cur);
            ++freq[cur];
        }
    }

    printf("%lld\n", ans);

    return 0;
}
