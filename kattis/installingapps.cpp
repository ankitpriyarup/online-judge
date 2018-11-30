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
using app = tuple<int, int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, c;
    cin >> n >> c;
    vector<app> apps;

    int need, store, idx;
    for (int i = 0; i < n; ++i) {
        cin >> need >> store;
        apps.emplace_back(need, store, i);
    }

    sort(begin(apps), end(apps), [](const app& a, const app& b) {
        int req_space_ab, req_space_ba;
        int a_need, a_store, a_idx;
        int b_need, b_store, b_idx;
        tie(a_need, a_store, a_idx) = a;
        tie(b_need, b_store, b_idx) = b;

        req_space_ab = req_space_ba = a_store + b_store;
        req_space_ab = max(req_space_ab, a_need);
        req_space_ab = max(req_space_ab, a_store + b_need);

        req_space_ba = max(req_space_ba, b_need);
        req_space_ba = max(req_space_ba, b_store + a_need);

        return req_space_ab < req_space_ba or (req_space_ab == req_space_ba and a_store < b_store);
    });

    vector<vector<int>> dp(n + 1, vector<int>(c + 1));
    vector<vector<int>> prev(n + 1, vector<int>(c + 1, -1));

    /*
    // dp(i, j) = max(dp(i - 1, j), dp(i, j - 1), 1 + dp(i - 1, j - w));
    for (int j = 1; j <= c; ++j) {
        cout << (j % 10) << " ";
    }
    cout << '\n';
    */

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j <= c; ++j) {
            dp[i][j] = dp[i + 1][j];
            if (dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                prev[i][j] = -2;
            }

            tie(need, store, idx) = apps[i];
            if (max(need, store) <= j and 1 + dp[i + 1][j - store] > dp[i][j]) {
                dp[i][j] = 1 + dp[i + 1][j - store];
                prev[i][j] = idx;
            }

            // cout << dp[i][j] << " ";
        }
        // cout << '\n';
    }

    int ans = dp[0][c];
    vector<int> used;
    int i = 0;
    int j = c;
    while (i != n) {
        if (prev[i][j] == -1) {
            ++i;
        } else if (prev[i][j] == -2) {
            --j;
        } else {
            used.push_back(prev[i][j]);
            j -= get<1>(apps[i]);
            ++i;
        }
    }

    cout << ans << '\n';
    for (int x : used) {
        cout << (x + 1) << ' ';
    }
    cout << '\n';

    return 0;
}
