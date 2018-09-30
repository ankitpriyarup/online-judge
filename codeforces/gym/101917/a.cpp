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

    constexpr int MAXN = 1000000;
    constexpr int MOD = 1e9 + 7;
    vector<int> dp(MAXN + 1, 0);
    for (int i = 3; i <= 24; i += 3) {
        dp[i] = 1;
    }

    for (int i = 3; i <= MAXN; i += 3) {
        for (int j = 3; j <= min(i, 24); j += 3) {
            dp[i] += dp[i - j];
            if (dp[i] >= MOD)
                dp[i] -= MOD;
        }
    }

    int T;
    cin >> T;
    int x;
    while (T-- > 0) {
        cin >> x;
        cout << dp[x] << '\n';
    }

    return 0;
}
