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

constexpr int MAXN = 15;
int n;
int a[MAXN];
int dp[1 << MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    sort(a, a + n);

    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) {
                continue;
            }

            for (int j = i + 1; j < n; ++j) {
                if ((mask & (1 << j)) == 0) {
                    continue;
                }

                for (int k = j + 1; k < n; ++k) {
                    if ((mask & (1 << k)) == 0) {
                        continue;
                    }

                    if (a[i] + a[j] > a[k]) {
                        int submask = mask ^ (1 << i) ^ (1 << j) ^ (1 << k);

                        dp[mask] = max(dp[mask], 1 + dp[submask]);
                        ans = max(ans, dp[mask]);
                    }

                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
