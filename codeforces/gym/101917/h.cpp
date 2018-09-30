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

void solve() {
    ll n, k;
    cin >> n >> k;
    ++n;
    ll base = n * (n - 1) / 2LL;
    if (k < base) {
        cout << "Too drunk to count\n";
        return;
    }

    k -= base;
    if (k % (n - 1) != 0) {
        cout << "Too drunk to count\n";
        return;
    }

    ll ans = n + k / (n - 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while (T-- > 0) {
        solve();
    }

    return 0;
}
