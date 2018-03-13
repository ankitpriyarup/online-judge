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
constexpr int MOD = 1000000007;
constexpr int MAXK = 9;
int x[MAXK], y[MAXK];
int fact[MAXN], tcaf[MAXN];

int sum(const int& a, const int& b) {
    int c = (a + b);
    if (c >= MOD)
        c -= MOD;
    return c;
}

int prod(const int& a, const int& b) {
    return 1LL * a * b % MOD;
}

int modpow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (exp & p)
            res = prod(res, cur);
        cur = prod(cur, cur);
    }

    return res;
}

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

void gen_fact() {
    fact[0] = tcaf[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = prod(fact[i - 1], i);
    }
    tcaf[MAXN - 1] = inv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; --i) {
        tcaf[i] = prod(tcaf[i + 1], i + 1);
        assert(tcaf[i] == inv(fact[i]));
    }
}

int from(int x1, int y1, int x2, int y2) {
    assert(x1 <= x2 and y1 <= y2);
    int dx = x2 - x1;
    int dy = y2 - y1;

    return prod(fact[dx + dy], prod(tcaf[dx], tcaf[dy]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_fact();

    int n, m, k;
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", x + i, y + i);
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << k); ++mask) {
        int parity = 0;
        vector<pii> points;
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                points.emplace_back(x[i], y[i]);
                parity ^= 1;
            }
        }
        sort(begin(points), end(points));
        bool valid = true;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].second > points[j].second)
                    valid = false;
            }
        }
        if (!valid) continue;

        int ways = from(1, 1, points[0].first, points[0].second);
        for (int i = 0; i + 1 < points.size(); ++i) {
            ways = prod(ways, from(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second));
        }
        ways = prod(ways, from(points.back().first, points.back().second, n, m));

        if (parity) {
            ans = sum(ans, ways);
        } else {
            ans = sum(ans, MOD - ways);
        }
    }

    printf("%d\n", ans);

    return 0;
}
