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

constexpr int MAXN = 1000006;
int n;
int a[MAXN];
int before[MAXN];

int f_tree[MAXN];

int query(int x) {
    int res = 0;

    for (; x; x -= (x & -x)) {
        res += f_tree[x];
    }

    return res;
}

void update(int x) {
    for (; x < MAXN; x += (x & -x)) {
        f_tree[x]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> v;
    v.push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(begin(v), end(v));
    v.resize(unique(begin(v), end(v)) - begin(v));

    for (int i = 1; i <= n; ++i) {
        int x = lower_bound(begin(v), end(v), a[i]) - begin(v);
        before[i] = query(n) - query(x);
        update(x);
    }

    ll ans = 0LL;
    memset(f_tree, 0, sizeof(f_tree));
    for (int i = n; i; --i) {
        int x = lower_bound(begin(v), end(v), a[i]) - begin(v);
        int cur = query(x - 1);
        ans += 1LL * before[i] * cur;
        update(x);
    }

    cout << ans << '\n';

    return 0;
}
