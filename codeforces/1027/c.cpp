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

constexpr int MAXL = 10004;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

bool llesss(ll x1, ll y1, ll x2, ll y2) {
    return x1 * y2 < x2 * y1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    int n;
    while (T-- > 0) {
        scanf(" %d", &n);
        vector<int> by_len(MAXL, 0);
        vector<int> have;
        int x;
        for (int i = 0; i < n; ++i) {
            scanf(" %d", &x);
            if (++by_len[x] == 2) {
                have.push_back(x);
            }
            if (by_len[x] == 4) {
                have.push_back(x);
            }
        }

        pair<ll, ll> minscore = {1e9 + 7, 1};
        pair<int, int> sides = {0, 0};

        sort(begin(have), end(have));
        for (size_t i = 1; i < have.size(); ++i) {
            int a = have[i - 1];
            int b = have[i];
            ll p2 = 4LL * a * a + 8LL * a * b + 4LL * b * b;
            ll s = 1LL * a * b;
            ll g = gcd(p2, s);
            p2 /= g;
            s /= g;

            if (llesss(p2, s, minscore.first, minscore.second)) {
                minscore = {p2, s};
                sides = {a, b};
            }
        }

        printf("%d %d %d %d\n", sides.first, sides.first, sides.second, sides.second);
    }
    
    return 0;
}
