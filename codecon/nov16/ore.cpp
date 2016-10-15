#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>

#define P(x) cout << (#x) << " is " << x << '\n'

using namespace std;

int n, m;

string grid[1003][1003];

map<string, int> invert_map;
int invert[1003][1003];
int dp[1003];

int main() {
    // m is col, n is row
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        invert_map[grid[0][i]] = i;
        dp[i] = 1;
        invert[0][i] = i;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            invert[i][invert_map[grid[i][j]]] = j;
        }
    }

    int ans = 1;

    //cout << dp[0];
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            bool valid = true;
            for (int k = 0; k < n; ++k) {
                valid &= (invert[k][j] <= invert[k][i]);
            }

            if (valid) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
