#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

constexpr int MAXH = 500005;
int n, h;
ll f_tree[MAXH];

ll query(int ind) {
    ll ret = 0;

    for (int x = ind; x;  x -= (x & -x)) {
        ret += f_tree[x];
    }

    return ret;
}

void update(int ind, int v) {
    for (int x = ind; x < MAXH; x += (x & -x)) {
        f_tree[x] += v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &h);

    int x;
    bool begin = true;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (begin) {
            // printf("Range is [%d, %d)\n", 1, x + 1);
            update(1, 1);
            update(x + 1, -1);
        } else {
            // printf("Range is [%d, %d)\n", h - x + 1, h + 1);
            update(h - x + 1, 1);
            update(h + 1, -1);
        }

        begin = !begin;
    }

    ll min_val = 1e18;
    ll ways = 0;
    for (int y = 1; y <= h; ++y) {
        ll q = query(y);
        // printf("%d %lld\n", y, q);
        if (q < min_val) {
            min_val = q;
            ways = 0;
        }

        if (q == min_val) {
            ++ways;
        }
    }

    printf("%lld %lld\n", min_val, ways);

    return 0;
}
