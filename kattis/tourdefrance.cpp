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

constexpr int MAXN = 40;
int n, m;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf("%d", &n) == 1) {
        if (!n) break;
        scanf("%d", &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        for (int i = 0; i < m; ++i)
            scanf("%d", b + i);
        vector<double> v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v.push_back(static_cast<double>(b[j]) / a[i]);
            }
        }

        sort(begin(v), end(v));
        double ans = 0.0;
        for (int i = 1; i < v.size(); ++i) {
            ans = max(ans, v[i] / v[i - 1]);
        }

        printf("%.2lf\n", ans);
    }
    
    return 0;
}
