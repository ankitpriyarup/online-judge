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

constexpr int MAXN = 15;
int n;
ll L;
ll a[MAXN][MAXN];
vector<ll> dp[1 << MAXN][MAXN];

void dfs(int mask, int u, int pc, ll dist) {
    if (dist >= L || pc > (n + 3) / 2)
        return;

    // printf("dp[%x][%d] %lld\n", mask, u, dist);
    dp[mask][u].push_back(dist);
    for (int v = 1; v < n; ++v) {
        if (mask & (1 << v))
            continue;

        dfs(mask | (1 << v), v, pc + 1, dist + a[u][v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %lld", &n, &L);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %lld", &a[i][j]);
        }
    }

    dfs(1, 0, 1, 0LL);
    int full = (1 << n) - 1;
    for (int mask = 1; mask <= full; mask += 2) {
        for (int j = 1; j < n; ++j) {
            if ((mask & (1 << j)) == 0)
                continue;

            int other = (full ^ mask) | 1 | (1 << j);
            // printf("mask %x other %x\n", mask, other);

            assert((mask | other) == full);
            assert((mask & other) == ((1 << j) | 1));
            vector<ll>& a = dp[mask][j];
            vector<ll>& b = dp[other][j];
            sort(begin(a), end(a));
            sort(begin(b), end(b));

            int p2 = static_cast<int>(b.size()) - 1;
            for (int i = 0; p2 >= 0 and i < a.size(); ++i) {
                while (p2 > 0 and a[i] + b[p2] > L)
                    --p2;

                if (p2 >= 0 and a[i] + b[p2] == L) {
                    printf("possible\n");
                    return 0;
                }
            }
        }
    }

    printf("impossible\n");
    return 0;
}