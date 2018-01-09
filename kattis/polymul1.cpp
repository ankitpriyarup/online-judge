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

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, m;
        scanf("%d", &n);
        vector<ll> a(n + 1);
        for (int i = 0; i <= n; ++i) {
            scanf("%lld", &a[i]);
        }

        scanf("%d", &m);
        vector<ll> b(m + 1);
        for (int i = 0; i <= m; ++i) {
            scanf("%lld", &b[i]);
        }

        vector<ll> c(n + m + 1, 0LL);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                c[i + j] += 1LL * a[i] * b[j];
            }
        }

        while (c.size() > 1 and c.back() == 0) {
            c.pop_back();
        }

        printf("%lu\n", c.size() - 1);
        for (int i = 0; i < c.size(); ++i) {
            printf("%lld ", c[i]);
        }
        printf("\n");
    }
    
    return 0;
}
