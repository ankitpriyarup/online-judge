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
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);

        int last = -1;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            last = max(last, a[i] - 1);
        }

        printf("%d\n", n - last - 1);
    }

    return 0;
}
