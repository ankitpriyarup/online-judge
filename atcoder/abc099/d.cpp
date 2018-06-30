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

constexpr int MAXN = 505;
int n, c;
int d[MAXN][MAXN], a[MAXN][MAXN];

int freq[3][MAXN];

ll score(int idx, int dest) {
    ll res = 0LL;
    for (int cc = 1; cc <= c; ++cc) {
        res += 1LL * freq[idx][cc] * d[cc][dest];
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &c);
    for (int i = 1; i <= c; ++i) {
        for (int j = 1; j <= c; ++j) {
            scanf(" %d", &d[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %d", &a[i][j]);
            ++freq[(i + j) % 3][a[i][j]];
        }
    }

    ll best = 1e18;

    for (int c1 = 1; c1 <= c; ++c1) {
        ll cur_first = score(0, c1);
        if (cur_first > best) continue;
        for (int c2 = 1; c2 <= c; ++c2) {
            if (c1 == c2) continue;

            ll cur_second = cur_first + score(1, c2);
            if (cur_second > best) continue;

            for (int c3 = 1; c3 <= c; ++c3) {
                if (c1 == c3 or c2 == c3) continue;
                best = min(best, cur_second + score(2, c3));
            }
        }
    }

    printf("%lld\n", best);

    return 0;
}
