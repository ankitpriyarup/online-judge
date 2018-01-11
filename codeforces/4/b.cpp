#include <cstdio>

using namespace std;

constexpr int MAXN = 32;
int d;
int sumTime;
int a[MAXN], b[MAXN], res[MAXN];

int main() {
    scanf("%d %d", &d, &sumTime);
    int cur_sum = 0;
    for (int i = 0; i < d; ++i) {
        scanf("%d %d", a + i, b + i);
        cur_sum += a[i];
        res[i] = a[i];
    }

    int p = 0;
    for (; p < d and cur_sum < sumTime; ++cur_sum) {
        while (p < d and res[p] == b[p])
            ++p;

        if (p >= d) break;
        ++res[p];
    }

    if (cur_sum != sumTime) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < d; ++i) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }
    return 0;
}
