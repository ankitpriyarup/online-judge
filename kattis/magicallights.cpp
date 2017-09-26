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

constexpr int MAXN = 300005;
constexpr int MAXC = 120;
int n;
int color[MAXN];
int tin[MAXN], tout[MAXN];
vector<int> tree[MAXN];
int tt = 1;
bitset<MAXC> f_tree[MAXN];

bitset<MAXC> query(int ind) {
    bitset<MAXC> ret;
    for (int x = ind; x; x -= (x & -x)) {
        ret ^= f_tree[x];
    }

    return ret;
}

void update(int ind, bitset<MAXC> val) {
    for (int x = ind; x < MAXN; x += (x & -x)) {
        f_tree[x] ^= val;
    }
}

void dfs(int node, int par = -1) {
    tin[node] = tt++;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }

    tout[node] = tt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", color + i);
    }

    int parent;
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &parent);
        tree[parent].push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= n; ++i) {
        bitset<MAXC> bs;
        bs.set(color[i]);

        update(tin[i], bs);
        /*
        bitset<MAXC> res = query(tin[i]) ^ query(tin[i] - 1);
        printf("%d(%d) | %d %d %s %s\n", i, color[i], tin[i], tout[i], 
                bs.to_string().c_str(), res.to_string().c_str());
        */
    }

    int k, x;
    while (q-- > 0) {
        scanf("%d %d", &k, &x);
        if (k == 0) {
            bitset<MAXC> bs = query(tout[x] - 1) ^ query(tin[x] - 1);
            int ans = bs.count();
            printf("%d\n", ans);
        } else {
            // update x to color k
            if (color[x] == k) continue;

            bitset<MAXC> change;
            change.set(color[x]);
            color[x] = k;
            change.set(color[x]);
            update(tin[x], change);
        }
    }

    return 0;
}
