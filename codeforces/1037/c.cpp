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
    string s, t;
    cin >> s >> t;
    vector<int> dp(n);
    dp[0] = s[0] != t[0];

    for (int i = 1; i < n; ++i) {
        dp[i] = (s[i] != t[i]) + dp[i - 1];

        if (s[i - 1] == t[i] and s[i] == t[i - 1]) {
            dp[i] = min(dp[i], 1 + (i >= 2 ? dp[i - 2] : 0));
        }
    }

    cout << dp[n - 1] << '\n';

    return 0;
}
