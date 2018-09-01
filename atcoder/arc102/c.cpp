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

    ll n, k;
    cin >> n >> k;
    ll full = 0LL;
    for (int a = k; a <= n; a += k) {
        ++full;
    }
    // cout << "full " << full;
    ll ans = 1LL * full * full * full;
    if (k % 2 == 0) {
        ll half = 0;
        k >>= 1;
        for (int a = k; a <= n; a += 2 * k) {
            ++half;
        }
        // cout << "half " << half;
        ans += 1LL * half * half * half;
    }

    cout << ans << '\n';

    return 0;
}
