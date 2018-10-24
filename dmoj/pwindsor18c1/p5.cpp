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

    int maxn = 1001;
    vector<int> dp(maxn, 0);
    dp[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        dp[i] = i;
        for (int j = 1; j < i; ++j) {
            dp[i] = max(dp[i], dp[j] * dp[i - j]);
        }
    }

    int n;
    cin >> n;
    cout << dp[n];

    return 0;
}
