#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 100005;
int n, k;
char s[MAXN];
char upd[15];
int cmap[255];

int f_tree[4][10][10][MAXN];

/*
struct node {
    int len;
    // char, period, index
    int freq[4][11][11];

    node() {
        len = 0;
        memset(freq, 0, sizeof(freq));
    }

    node(char c) {
        len = 1;
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < 12; ++i) {
            freq[cmap[c]][i][0] = 1;
        }
    }

    node operator+(const node& other) {
        node ret;

        ret.len = len + other.len;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 12; ++j) {
                for (int k = 0; k < j; ++k) {
                    ret.freq[i][j][k] += freq[i][j][k] + freq[i][j][(k + len) % j];
                }
            }
        }

        return ret;
    }
};

node tree[2 * MAXN + 5];

void build_tree() {
    for (int i = 0; i < n; ++i) {
        tree[n + 1] = node(s[i]);
    }

    for (int i = n - 1; i > 0; --i) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}

node query(int a, int b) {
    a += n;
    b += n;

    node left = node();
    node right = node();

    while (a <= b) {
        if (a % 2 == 1) {
            left = left + tree[a];
            ++a;
        }

        if (b % 2 == 0) {
            right = tree[b] + right;
            --b;
        }

        a /= 2;
        b /= 2;
    }

    return left + right;
}
*/


// equivalent to a[x] += v
void update(int a, int b, int c, int x, int v) {
    for (int i = x; i < MAXN; i += (i & -i)) {
        f_tree[a][b][c][i] += v;
    }
}

int query(int a, int b, int c, int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
        ans += f_tree[a][b][c][i];
    }

    return ans;
}

int main() {
    cmap['A'] = 0;
    cmap['T'] = 1;
    cmap['C'] = 2;
    cmap['G'] = 3;

    scanf("%s", s);
    n = strlen(s);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j) {
            update(cmap[s[i - 1]], j - 1, i % j, i, 1);
        }
    }

    int q;
    scanf("%d", &q);

    int type, ind, l, r;
    while (q-- > 0) {
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d %s", &ind, upd);
            for (int j = 1; j <= 10; ++j) {
                update(cmap[s[ind - 1]], j - 1, ind % j, ind, -1);
            }
            s[ind - 1] = upd[0];
            for (int j = 1; j <= 10; ++j) {
                update(cmap[s[ind - 1]], j - 1, ind % j, ind, +1);
            }
        } else {
            scanf("%d %d %s", &l, &r, upd);
            int m = strlen(upd);
            int ans = 0;
            for (int i = 0; i < m; ++i) {
                ans += query(cmap[upd[i]], m - 1, (l + i) % m, r);
                ans -= query(cmap[upd[i]], m - 1, (l + i) % m, l - 1);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
