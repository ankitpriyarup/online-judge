#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int n;
int a[MAXN];

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);

        int ans = 0;
        int bad = 0;
        int paid = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            paid += a[i];
        }

        int first_late = 0;
        while (first_late < n and a[first_late] == 1) {
            ++first_late;
        }

        int late_fees = 100 * (n - first_late);
        int main_fees = 1000 * (n - paid);
        printf("%d\n", late_fees + main_fees);
    }
    return 0;
}
