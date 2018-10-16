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
ll x[MAXN], y[MAXN], h[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] >= 1)
            start = i;
    }

    for (ll cx = 0; cx <= 100; ++cx) {
        for (ll cy = 0; cy <= 100; ++cy) {
            ll hh = max(0LL, abs(x[start] - cx) + abs(y[start] - cy) + h[start]);
            bool all_pass = true;
            for (int i = 0; i < n; ++i) {
                ll dx = abs(x[i] - cx);
                ll dy = abs(y[i] - cy);
                if (max(hh - dx - dy, 0LL) != h[i]) {
                    all_pass = false;
                    break;
                }
            }

            if (all_pass) {
                cout << cx << " " << cy << " " << hh << '\n';
                return 0;
            }
        }
    }

    return 0;
}
