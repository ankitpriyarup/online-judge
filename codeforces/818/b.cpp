#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

const int MAXN = 102;
int n, m;
int a[MAXN];
int perm[MAXN];
bool used[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 1; i < m; ++i) {
        int diff = a[i] - a[i - 1];
        while (diff <= 0) {
            diff += n;
        }

        if ((perm[a[i - 1]] == 0 and !used[diff]) or perm[a[i - 1]] == diff) {
            perm[a[i - 1]] = diff;
            used[diff] = true;
        } else {
            printf("%d\n", -1);
            return 0;
        }
    }

    int p = 1;
    for (int i = 1; i <= n; ++i) {
        if (perm[i] == 0) {
            while (used[p])
                ++p;

            perm[i] = p;
            used[p] = true;
        }
        printf("%d%c", perm[i], " \n"[i == n]);
    }

    return 0;
}
