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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> p(n + 1, vector<ll>(m + 1, 0));

    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> p[i][j];
            p[i][j] += p[i][j - 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            p[i][j] += p[i - 1][j];
        }
    }

    int scale = 5000;
    vector<int> freq(scale * 10000 + 2, 0);
    int tot = 0;
    for (int h = 1; h <= n; ++h) {
        for (int w = 1; w <= m; ++w) {
            if (h * w < a or h * w > b)
                continue;

            double den = h * w;
            for (int i = h; i <= n; ++i) {
                for (int j = w; j <= m; ++j) {
                    ll num = p[i][j] - p[i - h][j] - p[i][j - w] + p[i - h][j - w];
                    double dens = num / den;
                    int dd = scale * dens;
                    ++freq[dd];
                    ++tot;
                }
            }
        }
    }

    int cur = 0;
    int lo = -1;
    int hi = -1;
    for (int i = 0; i < freq.size(); ++i) {
        cur += freq[i];
        if (lo == -1 and 2 * cur >= tot) {
            lo = i;
        }
        if (hi == -1 and 2 * cur > tot) {
            hi = i;
            break;
        }
    }

    double ans = (lo + hi) / 2.0 / scale;

    cout << fixed << setprecision(6) << ans << '\n';

    return 0;
}
