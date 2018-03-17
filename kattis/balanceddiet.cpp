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

constexpr int MAXN = 30;
int n;
int a[MAXN];
int sum;

int dfs(int p, int cur = 0) {
    if (p == n) return cur;
    int res = dfs(p + 1, cur);
    if (2 * (cur + a[p]) <= sum) {
        res = max(res, dfs(p + 1, cur + a[p]));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf("%d", &n) == 1) {
        if (n <= 0) break;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n);
        reverse(a, a + n);
        int ans = dfs(0);
        printf("%d %d\n", sum - ans, ans);
    }

    return 0;
}
