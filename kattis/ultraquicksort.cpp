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

constexpr int MAXN = 500005;
int f_tree[MAXN];

void update(int x, int d) {
    ++x;
    for (; x < MAXN; x += (x & -x)) {
        f_tree[x] += d;
    }
}

int query(int x) {
    ++x;
    int ans = 0;
    for (; x; x -= (x & -x)) {
        ans += f_tree[x];
    }

    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i) {
        scanf(" %d", &a[i]);
        b[i] = a[i];
    }
    sort(begin(b), end(b));
    b.erase(unique(begin(b), end(b)), end(b));

    ll inv = 0LL;
    for (int i = n - 1; i >= 0; --i) {
        int idx = lower_bound(begin(b), end(b), a[i]) - begin(b);
        inv += query(idx);
        update(idx, 1);
    }

    printf("%lld\n", inv);
    
    return 0;
}
