#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <bitset>

using namespace std;

const int MAXN = 250006;

int n;
int a[MAXN];
int ans[MAXN];

int main() {
    n = 0;
    int x;

    bitset<MAXN> seen;
    while(scanf("%d", &x) == 1) {
        if (x == -1) {
            break;
        }

        a[n] = x;
        seen[x] = true;
        ++n;
    }

    for (int i = 0; i < n; ++i) {
        // printf("Examining %d\n", a[i]);
        for (int p = 1; p <= MAXN; p <<= 1) {
            int y = a[i] ^ p;

            if (a[i] < y and y < MAXN and seen[y]) {
                // printf("%d works\n", y);
                ++ans[i];
            }

            for (int q = 1; q < p; q <<= 1) {
                int y = a[i] ^ q ^ p;

                if (a[i] < y and y < MAXN and seen[y]) {
                    // printf("%d works\n", y);
                    ++ans[i];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d:%d\n", a[i], ans[i]);
    }

    return 0;
}
