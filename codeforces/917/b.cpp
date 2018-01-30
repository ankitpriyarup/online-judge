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

constexpr int MAXN = 102;
constexpr int MAXK = 30;
int n, m;
vector<pair<int, int> > graph[MAXN];
char out[MAXN][MAXN];
bool done[MAXN][MAXN][MAXK];
bool dp[MAXN][MAXN][MAXK];

int solve(int a, int b, int c) {
    if (done[a][b][c])
        return dp[a][b][c];

    bool can_win = false;
    for (auto& e : graph[a]) {
        if (e.second >= c)
            can_win |= !solve(b, e.first, e.second);
    }

    done[a][b][c] = true;
    return dp[a][b][c] = can_win;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    int u, v;
    char s[5];
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %s", &u, &v, s);
        --u;
        --v;
        graph[u].push_back({v, s[0] - 'a'});
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool res = solve(i, j, 0);
            out[i][j] = res ? 'A' : 'B';
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%s\n", out[i]);
    }

    return 0;
}
