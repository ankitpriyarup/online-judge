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

constexpr int MAXN = 12;
constexpr int H = 6;
constexpr int MAXM = 500005;
constexpr int MAXK = 101;
int n, m, q;
int w[MAXN];
int freq[1 << MAXN];

// 0- h1, 1- h2
int dist[2][1 << H][1 << H];
// dp[i][j][k] = # of values with right half j and dist(i, val) = k
int dp[1 << H][1 << H][MAXK];
int ans[1 << MAXN][MAXK];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    int h1 = n >> 1;
    int h2 = n - h1;
    for (int i = 0; i < (1 << h1); ++i) {
        for (int j = 0; j < (1 << h1); ++j) {
            for (int k = 0; k < h1; ++k) {
                if ((i & (1 << k)) == (j & (1 << k))) {
                    dist[0][i][j] += w[k];
                }
            }
        }
    }

    for (int i = 0; i < (1 << h2); ++i) {
        for (int j = 0; j < (1 << h2); ++j) {
            for (int k = 0; k < h2; ++k) {
                if ((i & (1 << k)) == (j & (1 << k))) {
                    dist[1][i][j] += w[h1 + k];
                }
            }
        }
    }


    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        int x = 0;
        for (int i = n - 1; i >= 0; --i) {
            x <<= 1;
            x |= (s[i] - '0');
        }
        ++freq[x];
    }

    int right_mask = (1 << h1) - 1;
    for (int x = 0; x < (1 << n); ++x) {
        if (!freq[x]) continue;

        int le = x >> h1;
        int ri = x & right_mask;
        assert((le << h1 | ri) == x);
        for (int i = 0; i < (1 << h2); ++i) {
            int m = i << h1;
            dp[i][ri][dist[1][le][i]] += freq[x];
        }
    }

    for (int x = 0; x < (1 << n); ++x) {
        int le = x >> h1;
        int ri = x & right_mask;
        for (int j = 0; j < (1 << h1); ++j) {
            for (int kk = 0; kk < MAXK; ++kk) {
                int new_dist = kk + dist[0][ri][j];
                if (new_dist < MAXK)
                    ans[x][new_dist] += dp[le][j][kk];
            }
        }
    }

    int k;
    while (q-- > 0) {
        cin >> s >> k;
        int x = 0;
        for (int i = n - 1; i >= 0; --i) {
            x <<= 1;
            x |= (s[i] - '0');
        }

        int out = 0;
        for (int d = 0; d <= k; ++d) {
            out += ans[x][d];
        }

        cout << out << '\n';
    }

    return 0;
}
