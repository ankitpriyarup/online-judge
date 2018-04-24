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

constexpr int MAXN = 70005;
int n;
int a[MAXN];
int f_tree[MAXN];

int query(int x) {
    x += 1;
    int res = 0;
    for (; x; x -= (x & -x)) {
        res += f_tree[x];
    }

    return res;
}

void update(int x, int v) {
    x += 1;
    for (; x < MAXN; x += (x & -x)) {
        f_tree[x] += v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &a[i]);
        v.push_back(a[i]);
    }

    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(begin(v), end(v), a[i]) - begin(v);
        update(idx, 1);
        int leq = query(idx);
        // expect (i + 1) things to be leq
        // inversions += (i + 1) - leq
        ans += (i + 1) - leq;
    }

    printf("%lld\n", ans);

    return 0;
}
