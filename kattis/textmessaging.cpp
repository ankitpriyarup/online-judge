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

int p, k, l;
int a[1003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);

    int tc = 1;
    while (T-- > 0) {
        ll res = 0LL;
        scanf("%d %d %d", &p, &k, &l);
        for (int i = 0; i < l; ++i) {
            scanf("%d", a + i);
        }
        sort(a, a + l);
        reverse(a, a + l);

        for (int i = 0; i < l; ++i) {
            int block = i / k;
            res += 1LL * a[i] * (block + 1LL);
        }

        printf("Case #%d: %lld\n", tc++, res);
    }

    
    return 0;
}
