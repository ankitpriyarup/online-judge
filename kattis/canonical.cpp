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

constexpr ll INF = 1e18;

constexpr int MAXN = 103;
constexpr int MAXV = 2000006;

int n;
int a[MAXN];

ll dp[MAXV];
ll greedy[MAXV];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    sort(a, a + n);

    dp[0] = greedy[0] = 0;
    int ptr = 0;
    bool works = true;

    for (int i = 1; i < MAXV; ++i) {
        while (ptr < n - 1 and a[ptr + 1] <= i) {
            ptr += 1;
        }

        greedy[i] = 1 + greedy[i - a[ptr]];
        dp[i] = INF;

        for (int j = 0; j < n and a[j] <= i; ++j) {
            dp[i] = min(dp[i], 1 + dp[i - a[j]]);
        }

        if (greedy[i] != dp[i]) {
            works = false;
            break;
        }
    }

    printf("%s\n", works ? "canonical" : "non-canonical");

    return 0;
}
