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

constexpr int MAXN = 16004;
int n;
vector<int> tree[MAXN];
int score[MAXN], dp[MAXN];

void dfs(int u, int p) {
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] += max(0, dp[v]);
    }
    dp[u] += score[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &score[i]);
    }
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf(" %d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1);
    int ans = -1000;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);

    printf("%d\n", ans);
    
    return 0;
}
