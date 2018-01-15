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

constexpr int MAXN = 200005;
int n, m;
ll a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %d", &n, &m);
        ll cssum = 0LL;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", a + i);
            cssum += a[i];
        }

        ll econsum = 0LL;
        for (int i = 0; i < m; ++i) {
            scanf("%lld", b + i);
            econsum += b[i];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // s / n < (s - x) / (n - 1) ==> s * (n - 1) < n * (s - x)
            bool cs_smarter = cssum * (n - 1) < n * (cssum - a[i]);

            // s / m < (s + x) / (m + 1) ==> s * (m + 1) < m * (s + x)
            bool econ_smarter = econsum * (m + 1) < m * (econsum + a[i]);
            if (cs_smarter and econ_smarter) ++ans;
        }

        printf("%d\n", ans);
    }

    return 0;
}
