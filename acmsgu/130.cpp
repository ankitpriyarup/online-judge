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

using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 61;
ull line_dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    line_dp[0] = 1ULL;
    line_dp[1] = 0ULL;
    for (int i = 2; i < MAXN; ++i) {
        // dots 0, 1, ... i - 1
        // try connecting 0 to anything
        for (int j = 1; j < i; ++j) {
            line_dp[i] += line_dp[j - 1] * line_dp[i - j - 1];
        }
    }

    ull k;
    scanf(" %llu", &k);

    printf("%llu %llu\n", line_dp[2 * k], k + 1);

    return 0;
}
