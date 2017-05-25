#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 102;
int n, x;
int a[MAXN];

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int crossed = 0;
    for (int i = 0; x > 0 and i < n; ++i) {
        x -= a[i];
        ++crossed;
    }

    printf("%d\n", crossed);
    return 0;
}
