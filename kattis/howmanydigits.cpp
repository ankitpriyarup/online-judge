#include <cstdio>
#include <cmath>

using namespace std;

const int MAXV = 1000006;

int ans[MAXV];

int main() {
    ans[0] = ans[1] = ans[2] = ans[3] = 1;

    long double cur = log10(1LL) + log10(2LL) + log10(3LL) + log10(4LL);
    for (int i = 4; i < MAXV; ++i) {
        ans[i] = ceil(cur);
        cur += log10(i + 1);
    }

    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d\n", ans[n]);
    }

    return 0;
}
