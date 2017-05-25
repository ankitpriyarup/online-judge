#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 100005;

int n;
int a[3 * MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3 * n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + 3 * n);

    long long ans = 0LL;
    for (int i = n; i < 3 * n; i += 2) {
        ans += a[i];
    }

    printf("%lld\n", ans);

    return 0;
}
