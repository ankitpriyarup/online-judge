#include <cstdio>
#include <cstdlib>

int a[505];
int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &a[i]);
    }

    double ans = 0.0;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &u, &v, &w);
        --u; --v;
        double res = (a[u] + a[v]) / ((double)w);
        if (res > ans)
            ans = res;
    }

    printf("%.15lf\n", ans);

    return 0;
}
