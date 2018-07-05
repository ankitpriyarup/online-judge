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

constexpr int MAXN = 18;
int n;
int a[MAXN];
int dp[1 << MAXN];
bool done[1 << MAXN];

int solve(int mask) {
    if (mask == 0) return 0;
    for (int i = 0; i < n; ++i) {
        if (mask == (1 << i)) {
            return a[i];
        }
    }

    if (done[mask])
        return dp[mask];

    int ans = 1e9 + 7;
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0)
            continue;

        for (int j = i + 1; j < n; ++j) {
            if ((mask & (1 << j)) == 0) {
                continue;
            }

            int cost = max(a[i], a[j]);
            if (mask == ((1 << i) | (1 << j)))
                return cost;

            ans = min(ans, cost + a[i] + solve(mask & ~(1 << j)));
            ans = min(ans, cost + a[j] + solve(mask & ~(1 << i)));
            for (int k = 0; k < n; ++k) {
                if (mask & (1 << k))
                    continue;

                ans = min(ans, cost + a[k] + solve((mask | (1 << k)) & ~(1 << i) & ~(1 << j)));
            }
        }
    }

    done[mask] = true;
    return dp[mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &a[i]);
    }

    printf("%d\n", solve((1 << n) - 1));

    return 0;
}
