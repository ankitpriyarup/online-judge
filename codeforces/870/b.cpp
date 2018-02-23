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

constexpr int MAXN = 100005;
int n, k;
int a[MAXN];
int pref_min[MAXN];
int suff_min[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int max_val = a[0];

    pref_min[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref_min[i] = min(a[i], pref_min[i - 1]);
        max_val = max(max_val, a[i]);
    }

    suff_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suff_min[i] = min(suff_min[i + 1], a[i]);
    }

    if (k >= 3) {
        printf("%d\n", max_val);
    } else if (k == 2) {
        int ans = a[0];
        for (int i = 1; i < n; ++i) {
            ans = max(ans, max(pref_min[i - 1], suff_min[i]));
        }

        printf("%d\n", ans);
    } else {
        printf("%d\n", pref_min[n - 1]);
    }

    return 0;
}
