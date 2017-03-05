#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 505;

int n;
long long adj[MAXN][MAXN];

int a[MAXN];
long long ans[MAXN];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%I64d", &adj[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    for (int k = n; k >= 1; --k) {
        ans[k] = 0LL;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                adj[a[i]][a[j]] = min(adj[a[i]][a[j]], adj[a[i]][a[k]] + adj[a[k]][a[j]]);
            }
        }

        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= n; ++j) {
                ans[k] += adj[a[i]][a[j]];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        printf("%I64d ", ans[i]);
    }
    puts("");

    return 0;
}
