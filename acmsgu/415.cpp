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

vector<vector<char>> knapsack(const vector<int>& coins, int c) {
    int n = coins.size();
    vector<vector<char>> dp(n + 1, vector<char>(c + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= c; ++j) {
            dp[i + 1][j] |= dp[i][j];
            if (j + coins[i] <= c) {
                dp[i + 1][j + coins[i]] |= dp[i][j];
            }
        }
    }

    return dp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, c;
    cin >> n >> c;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    auto prefs = knapsack(coins, c);
    reverse(begin(coins), end(coins));
    auto suffs = knapsack(coins, c);
    reverse(begin(coins), end(coins));

    /*
    cout << "PREFIX\n";
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= c; ++j) {
            cout << (int)prefs[i][j];
        }
        cout << '\n';
    }

    cout << "SUFFIX\n";
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= c; ++j) {
            cout << (int)suffs[i][j];
        }
        cout << '\n';
    }
    */

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        const auto& p = prefs[i];
        const auto& s = suffs[n - i - 1];
        bool can_make = false;
        for (int k = 0; !can_make and k <= c; ++k) {
            can_make |= p[k] and s[c - k];
        }

        if (!can_make) {
            res.push_back(coins[i]);
        }
    }

    cout << res.size() << '\n';
    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}
