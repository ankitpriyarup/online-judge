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
    scanf("%d", &T);

    int n, a, b, c, d, x, y, m;
    int tc = 1;
    while (T-- > 0) {
        scanf("%d %d %d %d %d %d %d %d", &n, &a, &b, &c, &d, &x, &y, &m);
        int freq[3][3];
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; ++i) {
            ++freq[x % 3][y % 3];
            x = (1LL * a * x + b) % m;
            y = (1LL * c * y + d) % m;
        }

        ll res = 0LL;
        for (int i = 0; i < 9; ++i) {
            int i1 = i / 3;
            int i2 = i % 3;

            // 3 is
            ll fi = freq[i1][i2];
            res += 1LL * fi * (fi - 1) * (fi - 2) / 6LL;

            for (int j = i + 1; j < 9; ++j) {
                int j1 = j / 3;
                int j2 = j % 3;

                ll fj = freq[j1][j2];

                // 2 is 1 j
                if ((2 * i1 + j1) % 3 == 0 and (2 * i2 + j2) % 3 == 0) {
                    res += fi * (fi - 1) * fj / 2LL;
                }

                // 1 i 2 js
                if ((i1 + 2 * j1) % 3 == 0 and (i2 + 2 * j2) % 3 == 0) {
                    res += fi * fj * (fj - 1) / 2LL;
                }

                for (int k = j + 1; k < 9; ++k) {
                    int k1 = k / 3;
                    int k2 = k % 3;

                    ll fk = freq[k1][k2];

                    if ((i1 + j1 + k1) % 3 != 0 or (i2 + j2 + k2) % 3 != 0)
                        continue;

                    res += fi * fj * fk;
                }
            }
        }

        printf("Case #%d: %lld\n", tc++, res);
    }

    return 0;
}
