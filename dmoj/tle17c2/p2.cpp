#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <tuple>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 1000006;
constexpr int MAXK = 500005;
int k;
int a[MAXK];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + k);

    int q;
    scanf("%d", &q);
    int x;
    while (q-- > 0) {
        scanf("%d", &x);

        int under = lower_bound(a, a + k, x) - a;

        printf("%d\n", x - under);
    }

    return 0;
}
