#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>

using namespace std;

using ll = long long;

int inv[300];

int main() {
    memset(inv, -1, sizeof(inv));

    for (int i = 0; i <= 0xFF; ++i) {
        int p = (i ^ (i << 1)) & 0xFF;
        // printf("%d %d\n", i, p);
        inv[p] = i;
    }

    int n;
    scanf("%d", &n);

    int y;
    while (n-- > 0) {
        scanf("%d", &y);

        printf("%d ", inv[y]);
    }

    printf("\n");
    return 0;
}
