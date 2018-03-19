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

constexpr int MAXN = 100005;
int n;
int a[MAXN];
int great[MAXN];
int f_tree[MAXN];

int query(int x) {
    int res = 0;
    for (; x; x -= (x & -x)) {
        res += f_tree[x];
    }
    return res;
}

void update(int x, int d) {
    for (; x < MAXN; x += (x & -x)) {
        f_tree[x] += d;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        // should be i - 1 elements before it
        great[i] = (i - 1) - query(a[i]);
        update(a[i], 1);
    }

    ll ans = 0LL;
    memset(f_tree, 0, sizeof(f_tree));
    for (int i = n; i >= 1; --i) {
        ll less = query(a[i] - 1);
        ans += less * great[i];
        update(a[i], 1);
    }

    printf("%lld\n", ans);
    
    return 0;
}
