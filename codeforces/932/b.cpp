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

constexpr int MAXN = 1e6 + 6;
int ans[MAXN];
vector<int> by_k[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 10; ++i) {
        ans[i] = i;
        by_k[i].push_back(i);
    }
    
    for (int i = 10; i < MAXN; ++i) {
        int digprod = 1;
        int x = i;
        while (x > 0) {
            if (x % 10)
                digprod *= (x % 10);
            x /= 10;
        }

        ans[i] = ans[digprod];
        by_k[ans[i]].push_back(i);
    }

    int q, l, r, k;
    scanf("%d", &q);
    while (q-- > 0) {
        scanf("%d %d %d", &l, &r, &k);
        // let u = upper_bound
        // a[u] > x
        // a[u - 1] <= x
        int a = upper_bound(begin(by_k[k]), end(by_k[k]), l - 1) - begin(by_k[k]);
        int b = upper_bound(begin(by_k[k]), end(by_k[k]), r) - begin(by_k[k]);

        printf("%d\n", b - a);
    }

    return 0;
}
