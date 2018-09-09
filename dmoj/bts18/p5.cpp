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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = n - 2; j >= 0; --j) {
            dp[j + 1] += 1LL * a[i] * dp[j] % MOD;
            dp[j + 1] %= MOD;
            if (dp[j + 1] < 0) {
                dp[j + 1] += MOD;
            }
        }
        dp[0] += a[i];
        dp[0] %= MOD;
        if (dp[0] < 0) {
            dp[0] += MOD;
        }
    }

    for (int x : dp) {
        cout << x << ' ';
    }
   
    return 0;
}
