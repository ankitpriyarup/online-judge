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
#define x1 asuidhga
#define y1 asdughas

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 10004;
int n;
int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];

int cross(int a, int b, int c, int d) {
    ll res = 1LL * a * d - 1LL * b * c;

    return res >= 0 ? 1 : -1;
}

bool intersect(int i, int a, int b, int c, int d) {
    int s1 = cross(x1[i] - a, y1[i] - b, x2[i] - a, y2[i] - b);
    int s2 = cross(x1[i] - c, y1[i] - d, x2[i] - c, y2[i] - d);

    return s1 != s2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
    }

    int q;
    scanf("%d", &q);
    int a, b, c, d;
    while (q-- > 0) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        bool same = true;
        for (int i = 0; i < n; ++i) {
            if (intersect(i, a, b, c, d))
                same = !same;
        }

        printf("%s\n", same ? "same" : "different");
    }

    return 0;
}
