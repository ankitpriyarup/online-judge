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
using pii = pair<ll, ll>;

vector<int> a;
bool done[22][1 << 17];
ll dp[22][1 << 17];

ll solve(int node, int k) {
    assert(k >= 0);
    if (node >= a.size() or k == 0)
        return 0;
    if (done[k][node])
        return dp[k][node];

    ll ans = 0LL;
    for (int k1 = 0; k1 < k; ++k1) {
        ans = max(ans, a[node] + solve(2 * node + 1, k1) + solve(2 * node + 2, k - 1 - k1));
    }

    done[k][node] = true;
    return dp[k][node] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    scanf("%d %d", &n, &k);
    k >>= 1;
    int x, y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << i); ++j) {
            scanf("%d %d", &x, &y);
            a.push_back(x + y);
        }
    }

    printf("%lld\n", solve(0, k));

    return 0;
}
