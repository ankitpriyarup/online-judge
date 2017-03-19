#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 1000001;
const int MOD = 1000000000;
long long zeros[MAXN];
long long ans[MAXN];

int main() {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 5; j <= i; j *= 5) {
            zeros[i] += i / j;
        }
    }

    ans[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        ans[i] = ans[i - 1] * i;
        for (int j = zeros[i]; j > zeros[i - 1]; --j) {
            ans[i] /= 10;
        }

        ans[i] %= MOD;
    }

    int n;
    while (scanf("%d", &n)) {
        if (n == 0) break;

        printf("%lld\n", ans[n] % 10);
    }

    return 0;
}
