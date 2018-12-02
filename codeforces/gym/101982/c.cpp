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

constexpr int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    map<int, int> m;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        m[x]++;
    }

    vector<int> a;
    for (auto& p : m) {
        a.push_back(p.second);
    }

    n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j] + 1LL * a[i - 1] * dp[i - 1][j - 1] % MOD;
            while (dp[i][j] >= MOD)
                dp[i][j] -= MOD;
        }
    }

    cout << dp[n][k] << '\n';

    return 0;
}
