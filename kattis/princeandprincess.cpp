#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN2 = 252 * 252;
int n, p, q;
int a[MAXN2];
int b[MAXN2];
int binv[MAXN2];
int dp[MAXN2];
int f_tree[MAXN2];

int query(int ind) {
    int ans = 0;
    for (int x = ind; x; x -= (x & -x)) {
        ans = max(ans, f_tree[x]);
    }

    return ans;
}

void update(int ind, int val) {
    for (int x = ind; x < MAXN2; x += (x & -x)) {
        f_tree[x] = max(f_tree[x], val);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    for (int case_num = 1; case_num <= T; ++case_num) {
        scanf("%d %d %d", &n, &p, &q);
        ++p; ++q;
        for (int i = 1; i <= p; ++i) {
            scanf("%d", a + i);
        }
        memset(binv, -1, sizeof(binv));
        for (int i = 1; i <= q; ++i) {
            scanf("%d", b + i);
            binv[b[i]] = i;
        }

        memset(f_tree, 0, sizeof(f_tree));
        for (int i = 1; i <= p; ++i) {
            // find the maximum index 
            int j = binv[a[i]];
            if (j == -1) continue;

            dp[j] = 1 + query(j);
            update(j, dp[j]);
        }

        printf("Case %d: %d\n", case_num, query(q + 1));
    }

    return 0;
}
