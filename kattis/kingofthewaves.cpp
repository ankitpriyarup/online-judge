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

constexpr int MAXN = 1003;
int n;
char grid[MAXN][MAXN];
bool vis[MAXN];
vector<int> answer;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    answer.push_back(u);
    for (int v = 0; v < n; ++v) {
        if (grid[u][v] == '1') {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", grid[i]);
    }

    dfs(0);
    reverse(begin(answer), end(answer));

    if (answer.size() != n) {
        printf("%s\n", "impossible");
    } else {
        printf("%d", answer[0]);
        for (int i = 1; i < n; ++i) {
            printf(" %d", answer[i]);
        }
        printf("\n");
    }

    return 0;
}
