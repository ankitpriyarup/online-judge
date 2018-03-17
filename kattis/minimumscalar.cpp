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

int n;
int a[888], b[888];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    int tc = 1;
    while (T-- > 0) {
        printf("Case #%d: ", tc++);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", b + i);
        }

        sort(a, a + n);
        sort(b, b + n);
        reverse(b, b + n);

        ll res = 0LL;
        for (int i = 0; i < n; ++i) {
            res += 1LL * a[i] * b[i];
        }
        printf("%lld\n", res);
    }
    
    return 0;
}
