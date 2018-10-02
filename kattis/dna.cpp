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

constexpr int MAXN = 1000006;
constexpr int INF = 1e9 + 7;
int n;
string s;
int dp[MAXN][2];

int solve(int idx, bool flip) {
    bool has_b = (s[idx] == 'B') ^ flip;
    if (idx == 0) {
        return has_b;
    }

    int& ret = dp[idx][flip];
    if (ret != -1) return ret;

    ret = INF;
    if (has_b) {
        // toggle just this
        ret = min(ret, 1 + solve(idx - 1, flip));
        // flip the whole thing
        ret = min(ret, 1 + solve(idx - 1, !flip));
    } else {
        ret = min(ret, solve(idx - 1, flip));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> s;

    memset(dp, -1, sizeof(dp));
    cout << solve(n - 1, false) << '\n';

    return 0;
}
