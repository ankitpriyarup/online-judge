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

constexpr ll INF = 1e18;

struct DP {
    int n, m;
    vector<pii> a, b;
    vector<pair<int, ll> > res;
    vector<int> lows;

    DP(vector<pii>& _a, vector<pii>& _b):
        a(begin(_a), end(_a)),
        b(begin(_b), end(_b)),
        n(_a.size()),
        m(_b.size()),
        lows(n),
        res(n, make_pair(-1, 0LL)) {
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < m and _a[i].first > _b[j].first)
                ++j;

            lows[i] = j;
        }
    };

    int lo(int ind) { return lows[ind]; }
    int hi(int ind) { return m; }

    ll f(int ind, int k) {
        assert(0 <= k and k < m);
        assert(0 <= ind and ind < n);
        ll dx = b[k].first - a[ind].first;
        ll dy = b[k].second - a[ind].second;
        if (dx <= 0LL or dy <= 0LL)
            return 0LL;
        return dx * dy;
    }

    void store(int ind, int k, ll v) {
        res[ind] = {k, v};
    }

    void rec(int L, int R, int LO, int HI) {
        if (L >= R) return;
        int mid = (L + R) >> 1;
        // printf("Solving for %d in range [%d, %d)\n", mid, LO, HI);
        pair<ll, int> best(-INF, -LO);
        for (int k = max(LO, lo(mid)); k < min(HI, hi(mid)); ++k) {
            best = max(best, make_pair(f(mid, k), -k));
            // printf("Score %lld at %d\n", f(mid, k), k);
        }

        // printf("Storing %lld at %d\n", best.first, -best.second);
        store(mid, -best.second, best.first);
        rec(L, mid, LO, -best.second + 1);
        rec(mid + 1, R, -best.second, HI);
    }

    void solve(int L, int R) {
        rec(L, R, 0, m);
    }
};

vector<pii> simple(const vector<pii>& bl) {
    vector<pii> res;
    for (const pii& p : bl) {
        while (!res.empty() and res.back().first == p.first and res.back().second >= p.second)
            res.pop_back();

        if (res.empty() or p.second < res.back().second)
            res.push_back(p);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf(" %d %d", &n, &m);
    // time, price
    vector<pii> bl(n), ur(m);
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &bl[i].second, &bl[i].first);
    }
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d", &ur[i].second, &ur[i].first);
        ur[i].first *= -1;
        ur[i].second *= -1;
    }

    bool brute = false;
    ll realans = 0LL;

    if (n <= 10 and m <= 10) {
        brute = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ll dx = -ur[j].first - bl[i].first;
                ll dy = -ur[j].second - bl[i].second;
                if (dx <= 0 or dy <= 0)
                    continue;
                realans = max(realans, dx * dy);
            }
        }
    }

    sort(begin(bl), end(bl));
    sort(begin(ur), end(ur));
    auto blfix = simple(bl);
    auto urfix = simple(ur);
    reverse(begin(urfix), end(urfix));
    for (pii& p : urfix) {
        p.first *= -1;
        p.second *= -1;
    }

    /*
    for (pii& p : blfix) {
        printf("%d %d\n", p.first, p.second);
    }
    printf("---\n");
    for (pii& p : urfix) {
        printf("%d %d\n", p.first, p.second);
    }
    */

    DP solver(blfix, urfix);
    solver.solve(0, blfix.size());
    ll ans = 0LL;
    for (int i = 0; i < blfix.size(); ++i) {
        // printf("Best for starting at index %d is %lld\n", i, solver.res[i].second);
        ans = max(ans, solver.res[i].second);
    }

    if (brute and ans != realans) {
        printf("Got %lld exp %lld\n", ans, realans);
        return -1;

        /*
        for (pii& p : bl) {
            printf("%d %d\n", p.first, p.second);
        }
        printf("---\n");
        for (pii& p : ur) {
            printf("%d %d\n", -p.first, -p.second);
        }
        */
    }
    printf("%lld\n", ans);
    return 0;
}
