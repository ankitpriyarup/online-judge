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
    int n, l, a;
    cin >> n >> l >> a;

    int last = 0;

    int t, li;
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        cin >> t >> li;
        ans += (t - last) / a;
        last = t + li;
    }

    ans += (l - last) / a;
    cout << ans << '\n';

    return 0;
}
