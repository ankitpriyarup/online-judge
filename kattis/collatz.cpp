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

constexpr int MAXN = 1000006;

vector<ll> collatz(ll x) {
    // printf("Starting at %lld\n", x);
    vector<ll> res = {x};
    while (res.back() != 1LL) {
        ll y = (res.back() % 2 == 1) ? 3 * res.back() + 1 : res.back() / 2;
        res.push_back(y);
        // printf("Push %lld\n", y);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        if (a == 0 or b == 0) break;

        vector<ll> x = collatz(a);
        vector<ll> y = collatz(b);
        int xbuf = 0;
        int ybuf = 0;
        if (x.size() > y.size()) {
            xbuf = x.size() - y.size();
        } else {
            ybuf = y.size() - x.size();
        }

        if (x[xbuf] == y[ybuf]) {
            printf("%d needs %d steps, %d needs %d steps, they meet at %lld\n", a, xbuf, b, ybuf, x[xbuf]);
        } else {
            int lo = 0;
            int hi = x.size() - xbuf - 1;
            while (lo + 1 < hi) {
                int mid = (lo + hi) >> 1;
                if (x[xbuf + mid] == y[ybuf + mid]) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }

            printf("%d needs %d steps, %d needs %d steps, they meet at %lld\n", a, xbuf + hi, b, ybuf + hi, x[xbuf + hi]);
        }
    }

    return 0;
}
