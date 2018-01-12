#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int res = min(n, k) + 1;

    for (int i = 1; n; ++i) {
        int lost = (n + k - 1) / k;
        n -= lost;
        res = max(res, 1 + i + min(n, k));
    }

    printf("%d\n", res);

    return 0;
}
