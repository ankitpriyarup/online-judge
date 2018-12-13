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

    int n;
    cin >> n;
    vector<int> a(n);
    int tot = 0;
    for (int i =  0; i < n; ++i) {
        cin >> a[i];
        tot += a[i];
    }

    constexpr int MAXV = 500000;
    bitset<MAXV> old, cur;
    old[0] = 1;
    for (int i = 0; i < n; ++i) {
        cur = old | (old << a[i]);
        old = cur;
        cur.reset();
    }

    int ans = tot;
    for (int i = 0; 2 * i <= tot; ++i) {
        if (old[i])
            ans = min(ans, tot - i - i);
    }

    cout << ans << '\n';

    return 0;
}
