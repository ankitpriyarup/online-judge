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

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    constexpr ll INF = 1e12;
    vector<vector<ll>> dp(2, vector<ll>(n + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < 2; ++k) {
            dp[k][i + 1] = min(dp[k][i] + a[i], dp[1 - k][i] + b[i]);
        }
    }

    cout << dp[0][n] << '\n';

    return 0;
}
