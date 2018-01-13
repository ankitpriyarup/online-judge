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

constexpr int MAXN = 102;
int n;
ll a[MAXN][MAXN];

ll f(ll x) {
    ll total = 0LL;
    for (int i = 0; i < n; ++i) {
        ll row_sum = 0LL;
        for (int j = 0; j < n; ++j) {
            row_sum += a[i][j];
        }
        
        total += x - row_sum;
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    ll lo = -1e16;
    ll hi = 1e16;

    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2LL;
        if (f(mid) < mid) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    for (int i = 0; i < n; ++i) {
        ll row_sum = 0LL; 
        for (int j = 0; j < n; ++j) {
            row_sum += a[i][j];
        }

        a[i][i] = hi - row_sum;
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << (j == n - 1 ? '\n' : ' ');
    }

    return 0;
}
