#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <tuple>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 1000006;
int n;
int a[MAXN];
int inv[MAXN];
int fear[MAXN];

int max_f_tree[MAXN];

int ans[MAXN];

int max_query(int ind) {
    int res = -1;
    for (int x = ind; x; x -= (x & -x)) {
        res = max(res, max_f_tree[x]);
    }

    return res;
}

void max_update(int ind, int v) {
    for (int x = ind; x < MAXN; x += (x & -x)) {
        max_f_tree[x] = max(v, max_f_tree[x]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    scanf("%d %d", &n, &q); 
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        inv[a[i]] = i;
    }

    memset(max_f_tree, -1, sizeof(max_f_tree));
    for (int i = n; i >= 1; --i) {
        int ind = inv[i];
        fear[ind] = max_query(ind);
        max_update(ind, ind);
    }

    int l, r;
    while (q-- > 0) {
        scanf("%d %d", &l, &r);
        int ans = 0;
        for (int i = l; i <= r; ++i) {
            if (fear[i] < l)
                ++ans;
        }

        printf("%d\n", ans);
    }

    return 0;
}
