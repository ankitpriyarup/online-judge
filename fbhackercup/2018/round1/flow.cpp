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

constexpr int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<string> grid(3);
    for (int i = 0; i < 3; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> dp(3, vector<int>(n + 1, 0));
    dp[2][n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (grid[0][i] == '.' and grid[1][i] == '.') {
            dp[0][i] = dp[1][i + 1];
            dp[1][i] = dp[0][i + 1];
        }

        if (grid[2][i] == '.' and grid[1][i] == '.') {
            dp[2][i] = dp[1][i + 1];
            dp[1][i] = (dp[1][i] + dp[2][i + 1]) % MOD;
        }
    }

    cout << dp[0][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}
