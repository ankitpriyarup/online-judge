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

constexpr int MAXN = 16;
int n;
string s[MAXN];
int dp[1 << MAXN][MAXN];
int overlap[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j + 5 <= s[i].size(); ++j) {
            if (s[i].substr(j, 5) == "Hodor") {
                ++dp[1 << i][i];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            string t = s[i] + s[j];
            for (int k = s[i].size() - 4; k + 5 <= t.size(); ++k)
                if (t.substr(k, 5) == "Hodor")
                    overlap[i][j]++;
        }
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        if ((mask & (mask - 1)) == 0) {
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) {
                continue;
            }

            for (int j = 0; j < n; ++j) {
                if (i == j or ((mask & (1 << j)) == 0)) {
                    continue;
                }

                dp[mask][i] = max(dp[mask][i], dp[mask ^ (1 << i)][j] + overlap[j][i]);
            }

            ans = max(ans, dp[mask][i]);
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
