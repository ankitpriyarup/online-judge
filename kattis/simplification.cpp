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

constexpr int MAXN = 200005;
constexpr int INF = 1e9 + 7;
int n;
int x[MAXN], y[MAXN];
int vals[MAXN];
bool used[MAXN];

int forwards[MAXN];
int backwards[MAXN];

// Al.Cash's trees: http://codeforces.com/blog/entry/18051
pii t[2 * MAXN];

void build() {
    // build the tree
    for (int i = n; i > 0; --i)
        t[i] = min(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, pii value) {
    // set value at position p
    for (t[p += n + 1] = value; p > 1; p >>= 1)
        t[p >> 1] = min(t[p], t[p ^ 1]);
}

pii query(int l, int r) {
    pii res = {INF, l - 1};

    for (l += n + 1, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = min(t[l++], res);

        if (r & 1)
            res = min(res, t[--r]);
    }

    return res;
}

inline int cross(int a, int b, int c) {
    int x1 = x[b] - x[a];
    int y1 = y[b] - y[a];

    int x2 = x[c] - x[a];
    int y2 = y[c] - y[a];

    return abs(x1 * y2 - x2 * y1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    scanf("%d %d", &n, &m);
    int moves = n - m;

    for (int i = 0; i <= n; ++i) {
        scanf("%d %d", x + i, y + i);
        backwards[i] = i - 1;
        forwards[i] = i + 1;
    }

    t[n + 1] = {INF, 0};
    t[n + 1 + n] = {INF, 0};
    for (int i = 1; i < n; ++i) {
        t[n + 1 + i] = {cross(i - 1, i, i + 1), i};
    }

    build();

    for (int i = 0; i < moves; ++i) {
        pii res = query(1, n);
        int ind = res.second;
        modify(ind, {INF, ind});

        assert(ind > 0 and ind < n);

        printf("%d\n", ind);
        int a = backwards[ind];
        int c = forwards[ind];
        assert(a >= 0 and a <= n);
        assert(c >= 0 and c <= n);
        if (a > 0 and a < n) {
            int aa = backwards[a];
            assert(aa >= 0 and aa <= n);
            modify(a, {cross(aa, a, c), a});
        }

        if (c > 0 and c < n) {
            int cc = forwards[c];
            assert(cc >= 0 and cc <= n);
            modify(c, {cross(a, c, cc), c});
        }

        forwards[a] = c;
        backwards[c] = a;
    }

    return 0;
}

