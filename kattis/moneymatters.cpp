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

constexpr int MAXN = 10004;
int n, m;
vector<int> graph[MAXN];
int score[MAXN];
bool vis[MAXN];
int cur;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    cur += score[u];
    for (int v : graph[u])
        dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &score[i]);
    }
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool poss = true;
    for (int i = 0; poss and i < n; ++i) {
        cur = 0;
        dfs(i);
        if (cur != 0)
            poss = false;
    }

    printf("%sPOSSIBLE\n", poss ? "" : "IM");
    
    return 0;
}
