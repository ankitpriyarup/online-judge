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

constexpr int MAXN = 200005;
int n;
int a[MAXN];
int dp[MAXN];
int last[MAXN];
// val -> idx with best dp
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 1; i <= n; ++i)
        scanf(" %d", &a[i]);

    for (int i = 1; i <= n; ++i) {
        last[i] = m[a[i] - 1];
        dp[i] = 1 + dp[last[i]];

        if (dp[i] > dp[m[a[i]]]) {
            m[a[i]] = i;
        }
    }

    int src = 1;
    for (int i = 1; i <= n; ++i)
        if (dp[i] > dp[src]) src = i;
    printf("%d\n", dp[src]);
    vector<int> stk;
    while (src) {
        stk.push_back(src);
        src = last[src];
    }

    while (!stk.empty()) {
        printf("%d ", stk.back());
        stk.pop_back();
    }
    
    return 0;
}
