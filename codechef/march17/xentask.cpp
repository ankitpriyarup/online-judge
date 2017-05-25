#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <complex>

using namespace std;

const int MAXN = 100005;
int n;
int x[MAXN];
int y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", x + i);
        for (int i = 0; i < n; ++i)
            scanf("%d", y + i);

        long long a1 = 0LL;
        long long a2 = 0LL;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                a2 += x[i];
                a1 += y[i];
            } else {
                a1 += x[i];
                a2 += y[i];
            }
        }

        printf("%lld\n", min(a1, a2));
    }

    return 0;
}
