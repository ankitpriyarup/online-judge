#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const int LOGN = 30;

int n, m;
int a[LOGN][MAXN];
int l[MAXN], r[MAXN], q[MAXN], res[MAXN];

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &l[i], &r[i], &q[i]);
        // set [l[i], r[i]] |= q[i]
        // difference array + prefix sum for each bit. Easiest.
        for (int j = LOGN - 1; j >= 0; --j) {
            if (q[i] & (1 << j)) {
                a[j][l[i]] += 1;
                a[j][r[i] + 1] -= 1;
            }
        }
    }

    // prefix over twice.
    for (int j = 0; j < LOGN; ++j) {
        for (int i = 1; i <= n; ++i) {
            a[j][i] += a[j][i - 1];
            res[i] |= (1 << j) * (a[j][i] > 0);
        }

        for (int i = 1; i <= n; ++i) {
            a[j][i] = a[j][i] > 0;
        }
        for (int i = 1; i <= n; ++i) {
            a[j][i] += a[j][i - 1];
        }
    }

    /*
    for (int j = 0; j <= 2; ++j) {
        for (int i = 1; i <= n; ++i) {
            cout << (a[j][i] - a[j][i - 1]) << ' ';
        }
        cout << '\n';
    }
    */

    // ensure that all things are correct
    bool valid = true;
    for (int i = 0; i < m; ++i) {
        for (int j = LOGN - 1; j >= 0; --j) {
            int s = a[j][r[i]] - a[j][l[i] - 1];

            if ((s == (r[i] - l[i] + 1) and (q[i] & (1 << j)) == 0)
             or (s != (r[i] - l[i] + 1) and (q[i] & (1 << j)) > 0)) {
                /*
                cout << i << " " << j << '\n';
                cout << s << " " << (q[i] & (1 << j)) << '\n';
                */
                valid = false;
            }
        }
    }

    if (!valid) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 1; i <= n; ++i) {
            printf("%d%c", res[i], " \n"[i == n]);
        }
    }

    return 0;
}
