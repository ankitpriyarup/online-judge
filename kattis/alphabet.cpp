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

char s[55];
// min edits to make s = abcdefgh...
int dp[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    dp[0][0] = 0;
    int n = strlen(s);
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= 26; ++i) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 26; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1] + 1);
            if (s[i - 1] == ('a' + j - 1)) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }

    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 26; ++j) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */

    printf("%d\n", dp[n][26]);
    return 0;
}
