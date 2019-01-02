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
    vector<string> s(2);
    vector<vector<int>> scores(2, vector<int>(n + 1));
    for (int k = 0; k < 2; ++k) {
        cin >> s[k];
        s[k] = '.' + s[k];
        for (int i = 1; i <= n; ++i) {
            cin >> scores[k][i];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[0][i] != s[1][j] and scores[0][i] != scores[1][j] and ((s[0][i] == 'W') ^ (scores[0][i] < scores[1][j]))) {
                dp[i][j] = max(dp[i][j], scores[0][i] + scores[1][j] + dp[i - 1][j - 1]);
            }
        }
    }

    cout << dp[n][n] << '\n';
    
    return 0;
}
