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

    /*
     * number of paths of length 2. Can repeat and loop.
     */

    int n, m;
    scanf(" %d %d", &n, &m);
    vector<int> deg(n + 1);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d", &u, &v);
        ++deg[u];
        ++deg[v];
    }

    ll ans = 0LL;
    for (int u = 1; u <= n; ++u) {
        ans += 1LL * deg[u] * deg[u];
    }

    printf("%lld\n", ans);
    
    return 0;
}
