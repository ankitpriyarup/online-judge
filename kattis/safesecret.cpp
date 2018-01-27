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

constexpr int MAXN = 202;
constexpr ll INF = 1e18;
int n;
int val[MAXN];
char op[MAXN][5];

// 0 = min, 1 = max
// i, j = range inclusive
bool done[2][MAXN][MAXN];
ll dp[2][MAXN][MAXN];

ll solve(int kind, int l, int r) {
    if (l == r) {
        return val[l];
    }

    if (done[kind][l][r]) {
        return dp[kind][l][r];
    }

    ll min_val = INF;
    ll max_val = -INF;
    for (int i = l; i != r; i = (i + 1) % n) {
        ll lefts[] = {solve(0, l, i), solve(1, l, i)};
        ll rights[] = {solve(0, (i + 1) % n, r), solve(1, (i + 1) % n, r)};

        for (int k = 0; k < 2; ++k) {
            for (int l = 0; l < 2; ++l) {
                if (op[i][0] == '+' or op[i][0] == '?') {
                    min_val = min(min_val, lefts[k] + rights[l]);
                    max_val = max(max_val, lefts[k] + rights[l]);
                }

                if (op[i][0] == '-' or op[i][0] == '?') {
                    min_val = min(min_val, lefts[k] - rights[l]);
                    max_val = max(max_val, lefts[k] - rights[l]);
                }

                if (op[i][0] == '*' or op[i][0] == '?') {
                    min_val = min(min_val, lefts[k] * rights[l]);
                    max_val = max(max_val, lefts[k] * rights[l]);
                }
            }
        }
    }

    done[0][l][r] = done[1][l][r] = true;
    dp[0][l][r] = min_val;
    dp[1][l][r] = max_val;

    return dp[kind][l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", val + i);
        scanf("%s", op[i]);
    }

    for (int i = 0; i < n; ++i) {
        ll min = solve(0, i, (i + n - 1) % n);
        ll max = solve(1, i, (i + n - 1) % n);

        printf("%lld%lld", abs(min), abs(max));
    }
    printf("\n");

    return 0;
}
