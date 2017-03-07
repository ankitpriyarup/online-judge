#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 102;
int n, m;
long long f_tree[MAXN][MAXN][MAXN];

char command[20];

void update(int x, int y, int z, int v) {
    for (int i = x; i < MAXN; i += (i & -i)) {
        for (int j = y; j < MAXN; j += (j & -j)) {
            for (int k = z; k < MAXN; k += (k & -k)) {
                f_tree[i][j][k] += v;
            }
        }
    }
}

long long query(int x, int y, int z) {
    long long ans = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
        for (int j = y; j > 0; j -= (j & -j)) {
            for (int k = z; k > 0; k -= (k & -k)) {
                ans += f_tree[i][j][k];
            }
        }
    }

    return ans;
}

long long query(int x1, int y1, int z1, int x2, int y2, int z2) {
    long long ans = query(x2, y2, z2);
    ans -= query(x1 - 1, y2, z2);
    ans -= query(x2, y1 - 1, z2);
    ans -= query(x2, y2, z1 - 1);

    ans += query(x2, y1 - 1, z1 - 1);
    ans += query(x1 - 1, y2, z1 - 1);
    ans += query(x1 - 1, y1 - 1, z2);

    ans -= query(x1 - 1, y1 - 1, z1 - 1);

    return ans;
}

int main() {
    int T;
    scanf("%d", &T);

    int x1, y1, z1, x2, y2, z2, v;
    while (T-- > 0) {
        scanf("%d %d", &n, &m);
        memset(f_tree, 0, sizeof(f_tree));

        while (m-- > 0) {
            scanf("%s", command);

            if (command[0] == 'U') {
                scanf("%d %d %d %d", &x1, &y1, &z1, &v);
                long long old_v = query(x1, y1, z1, x1, y1, z1);
                update(x1, y1, z1, v - old_v);
            } else {
                scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
                long long ans = query(x1, y1, z1, x2, y2, z2);

                printf("%lld\n", ans);
            }
        }
    }

    return 0;
}
