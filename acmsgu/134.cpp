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

constexpr int MAXN = 16123;
int n;
vector<int> graph[MAXN];
int sz[MAXN];
int cent_score[MAXN];

void dfs(int u, int p = -1) {
    sz[u] = 1;
    cent_score[u] = 0;
    for (int v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        cent_score[u] = max(cent_score[u], sz[v]);
    }

    cent_score[u] = max(cent_score[u], n - sz[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf(" %d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1);

    int best_score = n + 1;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (cent_score[i] < best_score) {
            best_score = cent_score[i];
            ans.clear();
        }

        if (cent_score[i] == best_score) {
            ans.push_back(i);
        }
    }

    printf("%d %lu\n", best_score, ans.size());
    for (int x : ans) 
        printf("%d ", x);
    printf("\n");
   
    return 0;
}
