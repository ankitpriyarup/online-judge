#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 100005;
int n, r;
int f_tree[2 * MAXN];
int pos[MAXN];

void update(int idx, int delta) {
    for (int i = idx; i < 2 * MAXN; i += (i & -i)) {
        f_tree[i] += delta;
    }
}

int sum(int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= (i & -i)) {
        sum += f_tree[i];
    }

    return sum;
}

int main() {
    int T;
    scanf("%d", &T);

    int id, loc;
    while (T-- > 0) {
        memset(f_tree, 0, sizeof(f_tree));
        scanf("%d %d", &n, &r);
        for (int i = 1; i <= n; ++i) {
            update(i, 1);
            pos[i] = n - i + 1;
        }

        for (int i = n + 1; i <= n + r; ++i) {
            scanf("%d", &id);
            loc = pos[id];
            printf("%d ", n - sum(loc));
            update(loc, -1);
            update(i, 1);
            pos[id] = i;
        }

        puts("");
    }

    return 0;
}
