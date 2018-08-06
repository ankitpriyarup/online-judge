#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAXN = 100005;
int n, k, l;
int a[MAXN];
bool used[MAXN];

int main() {
    scanf(" %d %d %d", &n, &k, &l);
    for (int i = 0; i < n * k; ++i) {
        scanf(" %d", a + i);
    }
    sort(a, a + n * k);
    int cutoff = a[0] + l;
    int small_ptr = upper_bound(a, a + n * k, cutoff) - a - 1;
    int big_ptr = n * k - 1;
    bool poss = true;
    long long ans = 0LL;
    for (int i = 0; poss && i < n; ++i) {
        for (int j = 0; j < k - 1; ++j) {
            while (big_ptr >= 0 and used[big_ptr])
                --big_ptr;

            if (big_ptr < 0) {
                poss = false;
                break;
            }

            used[big_ptr] = true;
            --big_ptr;
        }

        if (!poss) break;

        while (small_ptr >= 0 and used[small_ptr])
            --small_ptr;
        if (small_ptr < 0) {
            poss = false;
            break;
        }

        ans += a[small_ptr];
        used[small_ptr] = true;
        --small_ptr;
    }

    if (!poss) {
        printf("0\n");
    } else {
        printf("%lld\n", ans);
    }

    return 0;
}
