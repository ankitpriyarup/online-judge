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

    ll x;
    cin >> x;
    // iterate over w  
    // min area ((w + 1) / 2) * w, max is 2 * w * w 
    // for odd, (w + 1) / 2 * w = (w^2 + w) / 2
    // for even, w / 2 * w = w^2 / 2
    // 2 * w^2 = x
    // w = sqrt(x / 2)
    //
    // w^2 / 2 = x
    //
    int start = max(1, (int) sqrt(x / 2.0));
    int end = min((int) 1e8, (int) sqrt(2.0 * x));
    ll ans = x;

    for (int w = start; w <= end + 1; ++w) {
        int lo = (w + 1) / 2;
        int hi = 2 * w;
        if (1LL * hi * w < x) {
            continue;
        }
        if (x <= 1LL * lo * w) {
            hi = lo;
        }

        while (lo + 1 < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (1LL * mid * w < x) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        ans = min(ans, 1LL * hi * w - x);
    }

    cout << ans << '\n';
    
    return 0;
}
