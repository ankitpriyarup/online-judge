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

constexpr int MAXN = 1003;
constexpr int INF = 1e9 + 7;
int n;

struct name {
    string first, last;
    vector<string> chunks;

    void read() {
        cin >> first >> last;
        for (int i = 0; i < first.size(); ++i) {
            first[i] = tolower(first[i]);
        }
        for (int i = 0; i < last.size(); ++i) {
            last[i] = tolower(last[i]);
        }

        chunks.push_back(last.substr(0, 1) + first.substr(0, 1));
        for (int i = 2; i <= last.size(); ++i) {
            chunks.push_back(last.substr(0, i) + first.substr(0, 1));
        }

        for (int i = 2; i <= first.size(); ++i) {
            chunks.push_back(last + first.substr(0, i));
        }
    }

    inline int size() const {
        return chunks.size();
    }

    bool operator<(const name& other) const {
        return chunks.back() < other.chunks.back();
    }
} names[MAXN];

int dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        names[i].read();
    }

    sort(names, names + n);

    for (int j = 0; j < names[0].size(); ++j) {
        dp[0][j] = j;
    }

    int ans = INF;
    for (int i = 1; i < n; ++i) {
        ans = INF;
        for (int k = 0; k < names[i].size(); ++k) {
            dp[i][k] = INF;
            for (int j = 0; j < names[i - 1].size(); ++j) {
                if (names[i - 1].chunks[j] < names[i].chunks[k]) {
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + k);
                }
            }

            ans = min(ans, dp[i][k]);
        }
    }

    cout << ans << '\n';

    return 0;
}
