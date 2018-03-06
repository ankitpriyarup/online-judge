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

constexpr int MAXN = 1e6 + 6;
constexpr int MOD = 1e9 + 7;
ll dp[MAXN];

ll solve(int x) {
    if (x < 0) {
        return 0;
    } else if (x == 0) {
        return 1;
    }

    ll& ret = dp[x];
    if (ret != -1) {
        return ret;
    }
    
    ret = solve(x - 3) + 2LL * solve(x - 2) + solve(x - 1);
    ret %= MOD;
    return ret;
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    printf("%lld\n", solve(n));

    return 0;
}
