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

int n, s, k;
double memo[10004][502];

// probability of throwing exactly k distinct numbers in n throws
double solve(int n, int k) {
    if (k <= 0 or k > n) return 0.0;

    if (n == 1) {
        return k == 1 ? 1.0 : 0.0;
    }

    double& res = memo[n][k];
    if (res > -0.5)
        return res;

    res = k * solve(n - 1, k) / s;
    res += (s - k + 1) * solve(n - 1, k - 1) / s;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &s, &k);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            memo[i][j] = -1.0;
        }
    }

    double ans = 0.0;
    for (int j = k; j <= s; ++j) {
        ans += solve(n, j);
    }

    printf("%.9lf\n", ans);
    
    return 0;
}
