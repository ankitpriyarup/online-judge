#include <cstdio>

using namespace std;

int main() {
    int N, T;
    int a[55];

    int case_num = 1;
    while (scanf("%d %d", &N, &T) == 2) {
        for (int i = 0; i < N; ++i) {
            scanf("%d", &a[i]);
        }

        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += a[i];
            if (sum > T) {
                printf("Case %d: %d\n", case_num++, i);
                break;
            }
        }

        if (sum <= T) {
            printf("Case %d: %d\n", case_num++, N);
        }
    }

    return 0;
}
