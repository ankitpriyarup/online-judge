#include <cstdio>
#include <algorithm>

using namespace std;

/*
 * 11000
 * 1 -> 0
 * 2 -> 1
 * 3 -> 1
 * 4 -> 2
 * 5 -> 2
 * 6 -> 3
 * 7 -> 3
 * 8 -> 4
 * 9 -> 4
 */

int score(int x) {
    return x / 2;
}

int main() {
    int T, N;
    int a[105];
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &a[i]);
        }

        if (N == 1) {
            printf("%d\n", 0);
            continue;
        }

        int ans = 0;
        if (a[0] == 0 && a[1] == 0) {
            ans += 1;
            a[1] = 1;
        }

        if (a[N - 1] == 0 && a[N - 2] == 0) {
            ans += 1;
            a[N - 2] = 1;
        }

        int run = 0;
        for (int i = 0; i < N; ++i) {
            if (a[i] == 0) {
                run++;
            } else {
                ans += score(run);
                run = 0;
            }
        }

        ans += score(run);
        printf("%d\n", ans);
    }

    return 0;
}
