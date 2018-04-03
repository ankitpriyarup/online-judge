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

int sgn(int x) {
    return x >= 0 ? 1 : -1;
}

struct piece {
    int len, pref, sum;
    piece(): len(0), pref(0), sum(0) {}
    piece(int len, int pref, int sum): len(len), pref(pref), sum(sum) {}

    bool operator<(const piece& other) const {
        if (pref == 0 and other.pref == 0) {
            return make_pair(sum, len) > make_pair(other.sum, other.len);
        }
        if (pref == 0) {
            return true;
        }
        if (other.pref == 0) {
            return false;
        }

        if (sum >= 0 and other.sum < 0) {
            return true;
        }
        if (sum < 0 and other.sum >= 0) {
            return false;
        }

        return make_pair(other.pref - other.sum, sum) > make_pair(pref - sum, other.sum);
    }
};

constexpr int INF = 1e8;
constexpr int MAXN = 333;
int n;
int dp[MAXN][MAXN * MAXN];

int solve(const vector<piece>& pieces, int a, int b) {
    if (b < 0)
        return -INF;
    if (a == n)
        return b == 0 ? 0 : -INF;

    int& res = dp[a][b];
    if (res != -1)
        return res;

    res = solve(pieces, a + 1, b);
    if (b + pieces[a].pref >= 0)
        res = max(res, pieces[a].len + solve(pieces, a + 1, b + pieces[a].sum));

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<piece> pieces;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int len = s.size();
        int pref = 0;
        int sum = 0;
        for (int j = 0; j < len; ++j) {
            sum += s[j] == '(' ? 1 : -1;
            pref = min(pref, sum);
        }

        pieces.push_back({len, pref, sum});
    }

    sort(begin(pieces), end(pieces));
    memset(dp, -1, sizeof(dp));
    int res = solve(pieces, 0, 0);

    cout << res << '\n';

    return 0;
}
