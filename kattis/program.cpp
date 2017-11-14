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

constexpr int MAXN = 1000006;
int n;
int updates[MAXN];
ll a[MAXN];
ll pref[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k, x;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        ++updates[x];
    }

    for (int i = 1; i < n; ++i) {
        if (updates[i] == 0) continue;

        for (int j = 0; j < n; j += i) {
            a[j] += updates[i];
        }
    }

    pref[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = a[i] + pref[i - 1];
    }

    int q;
    scanf("%d", &q);
    int l, r;
    while (q-- > 0) {
        scanf("%d %d", &l, &r);

        ll ans = pref[r];
        if (l) {
            ans -= pref[l - 1];
        }

        printf("%lld\n", ans);
    }
    
    return 0;
}
