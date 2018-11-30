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

constexpr int INF = 1e9 + 7;

void solve() {
    int s;
    cin >> s;
    vector<string> engines(s);
    // flush whitespace
    string query;
    getline(cin, query);

    for (int i = 0; i < s; ++i) {
        getline(cin, engines[i]);
    }

    int q;
    cin >> q;
    getline(cin, query);
    vector<int> queries(q, -1);
    for (int i = 0; i < q; ++i) {
        getline(cin, query);
        for (int j = 0; j < s; ++j) {
            if (query == engines[j]) {
                queries[i] = j;
                break;
            }
        }
    }

    if (s == 0 or q == 0) {
        cout << 0 << '\n';
        return;
    }

    // min number of switches to get prefix up to i ending at search engine j
    vector<vector<int>> dp(q, vector<int>(s, INF));
    for (int j = 0; j < s; ++j) {
        if (queries[0] != j) {
            dp[0][j] = 0;
        }
    }

    vector<int> dp_pref(s, INF);
    vector<int> dp_suff(s, INF);
    for (int i = 1; i < q; ++i) {
        dp_pref[0] = dp[i - 1][0];
        for (int j = 1; j < s; ++j) {
            dp_pref[j] = min(dp_pref[j - 1], dp[i - 1][j]);
        }

        dp_suff[s - 1] = dp[i - 1][s - 1];
        for (int j = s - 2; j >= 0; --j) {
            dp_suff[j] = min(dp_suff[j + 1], dp[i - 1][j]);
        }

        for (int j = 0; j < s; ++j) {
            if (queries[i] != j) {
                dp[i][j] = dp[i - 1][j];
            }

            if (j > 0)
                dp[i][j] = min(dp[i][j], dp_pref[j - 1] + 1);
            if (j + 1 < s)
                dp[i][j] = min(dp[i][j], dp_suff[j + 1] + 1);
        }
    }

    int ans = INF;
    for (int j = 0; j < s; ++j) {
        ans = min(ans, dp[q - 1][j]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc = 1;

    int T;
    cin >> T >> skipws;
    while (T-- > 0) {
        cout << "Case #" << tc++ << ": ";
        solve();
    }

    return 0;
}
