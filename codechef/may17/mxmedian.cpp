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

const int MAXN = 50004;
int n;
int a[2 * MAXN];
int b[2 * MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; ++i) {
            scanf("%d", a + i);
        }

        sort(a, a + 2 * n);
        int ans = a[n + n / 2];

        int start = 0;
        int end = 2 * n - 1;
        for (int i = 0; i < 2 * n; i += 2) {
            b[i] = a[start];
            b[i + 1] = a[end];
            ++start;
            --end;
        }

        printf("%d\n", ans);

        for (int i = 0; i < 2 * n; ++i) {
            printf("%d%c", b[i], i == 2 * n - 1 ? '\n' : ' ');
        }

    }

    return 0;
}
