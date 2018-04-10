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

    int T;
    scanf("%d", &T);
    int n, k, x;
    while (T-- > 0) {
        scanf("%d", &n);
        vector<ll> v;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &k);
            ll s = 0LL;
            while (k-- > 0) {
                scanf("%d", &x);
                s = s + x;
            }

            v.push_back(s);
        }

        sort(begin(v), end(v));
        ll pref = 0LL;
        ll num = 0LL;
        for (ll& y : v) {
            pref += y;
            num += pref;
        }

        printf("%.11Lf\n", num / static_cast<ld>(n));
    }
   
    return 0;
}
