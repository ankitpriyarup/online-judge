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

constexpr int MAXN = 20004;
int n, d;
int pts[MAXN][2];

int sieve[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve[0] = sieve[1] = -1;
    for (int i = 2; i < MAXN; ++i) {
        if (!sieve[i]) {
            for (int j = i; j < MAXN; j += i)
                sieve[j] = i;
        }
    }

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %d", &n, &d);
        ld dist = 0.0;
        int ans = 0;
        int curx = 0;
        int cury = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &pts[i][0], &pts[i][1]);
            int dx = curx - pts[i][0];
            int dy = cury - pts[i][1];
            dist += sqrt(dx * dx + dy * dy);
            curx = pts[i][0];
            cury = pts[i][1];

            if (dist <= d and sieve[i + 1] == i + 1)
                ans = i + 1;
        }

        printf("%d\n", ans);
    }

    return 0;
}
