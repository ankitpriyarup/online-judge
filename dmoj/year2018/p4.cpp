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

int l_digs[30], r_digs[30];
bool done[200][20][2][2];
bool dp[200][20][2][2];

bool find_sum(int sum, int pos, bool gl = false, bool lr = false) {
    if (pos == -1 and sum == 0) return true;
    if (sum < 0) return false;
    if (pos == -1) return false;

    // printf("%d %d %d %d\n", sum, pos, gl, lr);

    if (done[sum][pos][gl][lr])
        return dp[sum][pos][gl][lr];

    bool poss = false;
    for (int digit = 0; digit <= 9; ++digit) {
        bool valid = (sum >= digit) and (lr or digit <= r_digs[pos]) and (gl or digit >= l_digs[pos]);
        if (!valid) continue;

        poss |= find_sum(sum - digit, pos - 1, gl || digit > l_digs[pos], lr || digit < r_digs[pos]);
    }

    done[sum][pos][gl][lr] = true;
    return dp[sum][pos][gl][lr] = poss;
}

void parse(ll v, int* digits) {
    int i = 0;
    while (v > 0) {
        digits[i++] = v % 10;
        v /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll l, r;
    scanf("%lld %lld", &l, &r);
    parse(l, l_digs);
    parse(r, r_digs);

    int ans = 0;
    for (int i = 1; i <= 9 * 18; ++i) {
        if (find_sum(i, 19)) {
            ++ans;
        }
    }

    printf("%d\n", ans);

    return 0;
}
