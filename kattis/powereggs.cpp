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
using pii = pair<int, int>;

constexpr ll INF = 2e12;

// i eggs, j drops
ll dp[34][34];

void precomp() {
    for (int i = 0; i <= 32; ++i) {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= 32; ++j) {
        dp[1][j] = j;
    }

    for (int i = 2; i <= 32; ++i) {
        for (int j = 1; j <= 32; ++j) {
            // Either the egg breaks or it doesn't
            dp[i][j] = 1 + dp[i - 1][j - 1] + dp[i][j - 1];
            dp[i][j] = min(dp[i][j], INF);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    precomp();

    int T;
    scanf("%d", &T);
    int n, k;
    while (T-- > 0) {
        scanf("%d %d", &n, &k);
        bool found = false;
        for (int j = 0; !found and j <= 32; ++j) {
            if (dp[k][j] >= n) {
                printf("%d\n", j);
                found = true;
            }
        }

        if (!found) {
            printf("Impossible\n");
        }
    }

    return 0;
}
