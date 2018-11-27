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
    cin >> T;
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        vector<ll> p(n + 1, 0);
        vector<int> bounds = {0};
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            p[i] = p[i - 1] + a[i];
            if (a[i] <= m) {
                bounds.push_back(i);
            }
        }
        bounds.push_back(n + 1);

        // can contain at most one element of bounds
        int k = bounds.size();
        ll ans = m;
        for (int i = 1; i + 1 < k; ++i) {
            int pos = bounds[i];
            if (a[pos] != m) continue;
            ans = max(ans, p[bounds[i + 1] - 1] - p[bounds[i - 1]]);
        }

        printf("%lld\n", ans);
    }
    
    return 0;
}
