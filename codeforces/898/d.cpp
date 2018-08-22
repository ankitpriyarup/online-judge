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

struct BIT {
    int n;
    vector<int> data;
    BIT(int _n): n(_n) {
        data.assign(_n + 1, 0);
    }

    int query(int x) {
        int res = 0;
        for (; x; x -= (x & -x)) {
            res += data[x];
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l);
    }

    void update(int x, int v) {
        for (; x <= n; x += (x & -x)) {
            data[x] += v;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);
    vector<int> a(n + 1);
    BIT f(n);
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &a[i]);
        f.update(i, 1);
    }

    sort(begin(a), end(a));
    int l = 0;
    for (int r = 1; r <= n; ++r) {
        while (l < r and a[r] - a[l + 1] >= m) {
            ++l;
        }

        int have = f.query(l, r);
        int ridx = r;
        while (have >= k) {
            f.update(ridx--, -1);
            have = f.query(l, r);
        }
    }

    printf("%d\n", n - f.query(n));

    return 0;
}
