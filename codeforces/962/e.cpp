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
using edge = tuple<int, ll, ll, ll>;
using vi = vector<int>;

constexpr int MAXN = 200005;
constexpr ll INF = 1e16;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    ll x;
    char c;
    vector<ll> b, r;

    ll last_p = -INF;
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        scanf(" %lld %c", &x, &c);
        if (c == 'B')
            b.push_back(x);
        else if (c == 'R')
            r.push_back(x);
        else {
            if (last_p == -INF) {
                // have to connect up to here
                if (!b.empty())
                    ans += x - b[0];
                if (!r.empty())
                    ans += x - r[0];
            } else {
                // two options
                ll seg_score = x - last_p;
                ll best_blue = b.empty() ? x - last_p : max(b[0] - last_p, x - b.back());
                ll best_red = r.empty() ? x - last_p : max(r[0] - last_p, x - r.back());
                for (int i = 1; i < b.size(); ++i) {
                    best_blue = max(best_blue, b[i] - b[i - 1]);
                }
                for (int i = 1; i < r.size(); ++i) {
                    best_red = max(best_red, r[i] - r[i - 1]);
                }

                seg_score += x - last_p - best_blue;
                seg_score += x - last_p - best_red;

                if (b.empty() and r.empty()) {
                    seg_score = x - last_p;
                }

                // direct connect
                seg_score = min(seg_score, 2LL * (x - last_p));
                ans += seg_score;
            }

            b.clear();
            r.clear();
            last_p = x;
        }
    }

    if (!b.empty()) {
        if (last_p == -INF) {
            ans += b.back() - b[0];
        } else {
            ans += b.back() - last_p;
        }
    }

    if (!r.empty()) {
        if (last_p == -INF) {
            ans += r.back() - r[0];
        } else {
            ans += r.back() - last_p;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
