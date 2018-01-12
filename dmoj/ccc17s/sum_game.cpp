#include <cstdio>

using namespace std;

const int MAXN = 100005;

int n;
int a[MAXN];
int b[MAXN];

int main() {
    scanf("%d", &n);

    int x;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        a[i] = a[i - 1] + x;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        b[i] = b[i - 1] + x;

        if (b[i] == a[i]) {
            ans = i;
        }
    }

    printf("%d\n", ans);

    return 0;
}
