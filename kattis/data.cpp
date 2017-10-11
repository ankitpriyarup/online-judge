#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 15;
constexpr int MAXV = 14005;
int n;
int a[MAXN];
int score[MAXV];
int dp[1 << MAXN];
int sums[1 << MAXN];

void gen_sieve() {
    memset(score, 0, sizeof(score));
    for (int i = 2; i < MAXV; i += 2) {
        score[i] = 1;
    }
    for (int i = 3; i < MAXV; i += 2) {
        if (score[i] != 0) 
            continue;

        for (int j = i; j < MAXV; j += i) {
            ++score[j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_sieve();

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        sums[mask] = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sums[mask] += a[i];
            }
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        dp[mask] = score[sums[mask]];
        for (int submask = mask; submask; submask = (submask - 1) & mask) {
            dp[mask] = max(dp[mask], score[sums[submask]] + dp[mask ^ submask]);
        }
    }

    printf("%d\n", dp[(1 << n) - 1]);
    
    return 0;
}
