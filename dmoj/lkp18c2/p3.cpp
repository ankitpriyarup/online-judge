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
int n, m;
ll xs[MAXN], ys[MAXN];
ll tx[3], ty[3];

bool inside(int i) {
    ll v1x = tx[1] - tx[0];
    ll v1y = ty[1] - ty[0];
    ll v2x = tx[2] - tx[0];
    ll v2y = ty[2] - ty[0];

    ll px = xs[i] - tx[0];
    ll py = ys[i] - ty[0];

    // outer boundary is t v1 + (1 - t) v2. Just make sure that 0 <= t <= 1
    // p = a v1 + b v2
    // 0 <= a, b, a + b <= 1
    //
    // px = a v1x + b v2x
    // py = a v1y + b v2y
    // v1x v2x | px
    // v1y v2y | py
    ll a = v2y * px - v2x * py;
    ll b = -v1y * px + v1x * py;
    ll det = v1x * v2y - v2x * v1y;

    if (det < 0) {
        a = -a;
        b = -b;
        det = -det;
    }

    /*
    cout << "For pt " << i << "\n";
    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
    cout << "det = " << det << '\n';
    */

    return 0 <= a && a <= det && 0 <= b && b <= det && 0 <= a + b && a + b <= det;
}

int solve() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (inside(i)) {
            ans += 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> tx[j] >> ty[j];
        }
        cout << solve() << '\n';
    }
    
    return 0;
}
