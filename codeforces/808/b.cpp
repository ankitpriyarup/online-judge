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

const int MAXN = 200005;
int n, k;
int a[MAXN];
long long p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d %d", &n, &k);
    p[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        p[i] = p[i - 1] + a[i];
    }

    long long ans = 0LL;
    for (int end = k; end <= n; ++end) {
        ans += p[end] - p[end - k];
    }

    printf("%.9Lf\n", ((long double) ans) / (n - k + 1));

    return 0;
}
