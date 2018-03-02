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
int n;
int a[MAXN];

bool arith() {
    int d = a[1] - a[0];
    for (int i = 2; i < n; ++i) {
        if (a[i] - a[i - 1] != d)
            return false;
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }

        if (arith()) {
            printf("arithmetic\n");
        } else {
            sort(a, a + n);
            if (arith()) {
                printf("permuted arithmetic\n");
            } else {
                printf("non-arithmetic\n");
            }
        }
    }

    return 0;
}
