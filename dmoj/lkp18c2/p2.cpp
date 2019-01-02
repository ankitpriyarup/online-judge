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

    map<int, int> m;
    m[0] = 1;
    int n, k;
    cin >> n >> k;
    int cur = 0;
    ll ans = 0LL;
    int x;
    while (n-- > 0) {
        cin >> x;
        cur += x;
        cur %= k;

        ans += m[cur];
        m[cur] += 1;
    }

    cout << ans << '\n';
    
    return 0;
}
