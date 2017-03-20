#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 40004;
int n;
int a[MAXN];

int main() {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int l, r, x, y;
    while (q-- > 0) {
        scanf("%d %d %d %d", &l, &r, &x, &y);

        int ans = 0;
        for (int i = l; i <= r; ++i) {
            if (a[i] % x == y) {
                ++ans;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}

