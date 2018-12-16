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

constexpr int MAXN = 200005;
int n;
ll a[MAXN];
ll ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i += 2) {
        cin >> a[i];
    }

    a[0] = 0;
    ans[0] = 0;
    // partials sums of odd numbers are squares
    // a^2 - b^2 = (a + b) * (a - b)
    // find all matching a and b for each one?
    // see where they intersect
    for (int i = 2; i <= n; i += 2) {
        ans[i] = 1e15;
        for (ll x = 1; x * x < a[i]; ++x) {
            if (a[i] % x == 0) {
                ll y = a[i] / x;
                if ((x + y) & 1) continue;

                // a - b = x
                // a + b = y
                ll aa = (x + y) / 2;
                ll bb = (y - x) / 2;
                if (bb > ans[i - 2] and aa < ans[i]) {
                    ans[i - 1] = bb;
                    ans[i] = aa;
                }
            }
        }

        if (ans[i] == 1e15) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        ll x = ans[i] + ans[i - 1];
        ll y = ans[i] - ans[i - 1];
        cout << (x * y) << ' ';
    }

    return 0;
}
