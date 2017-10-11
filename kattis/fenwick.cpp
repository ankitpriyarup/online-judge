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

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 5000006;
int n;
ll f_tree[MAXN];

ll read(int ind) {
    ll res = 0;
    for (int x = ind; x; x -= (x & -x)) {
        res += f_tree[x];
    }

    return res;
}

void update(int ind, int v) {
    for (int x = ind + 1; x < MAXN; x += (x & -x)) {
        f_tree[x] += v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, ind, val;
    char cmd[5];

    scanf("%d %d", &n, &q);
    while (q-- > 0) {
        scanf("%s %d", cmd, &ind);
        if (cmd[0] == '+') {
            scanf("%d", &val);
            update(ind, val);

        } else {
            printf("%lld\n", read(ind));

        }
    }

    return 0;
}
