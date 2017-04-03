#include <cstdio>

using namespace std;

const int MAXN = 100005;
int n, m, k;
int a[MAXN];
int l[MAXN], r[MAXN], d[MAXN];

long long f_tree[2][MAXN];

// return a[1] + a[2] + ... + a[x]
long long query(int ind, int x) {
    long long ans = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
        ans += f_tree[ind][i];
    }

    return ans;
}

// equivalent to a[x] += v
void update(int ind, int x, long long v) {
    for (int i = x; i < MAXN; i += (i & -i)) {
        f_tree[ind][i] += v;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", l + i, r + i, d + i);
    }

    int x, y;
    for (int i = 1; i <= k; ++i) {
        scanf("%d %d", &x, &y);
        update(0, x, 1);
        update(0, y + 1, -1);
    }

    for (int i = 1; i <= m; ++i) {
        int times = query(0, i);
        // apply update[i] times
        update(1, l[i], 1LL * d[i] * times);
        update(1, r[i] + 1, -1LL * d[i] * times);
    }

    for (int i = 1; i <= n; ++i) {
        printf("%I64d%c", query(1, i) + a[i], i == n ? '\n' : ' ');
    }

    return 0;
}
