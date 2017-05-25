#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 100005;
int n;
long long a[MAXN];
long long p[MAXN];

// returns the greatest index such that a[i] < k
int find_end(long long k) {
    if (a[n] < k) {
        return n;
    }
    int lo = 1;
    int hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] < k) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return lo;
}

int solve(long long k) {
    if (a[1] >= k) {
        return n;
    }

    int end = find_end(k);

    // printf("end: %d\n", end);
    // this binary search counts how many snakes can be brought up to k
    int lo = 0;
    int hi = end;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        long long food = end - mid;
        long long sum = p[end] - p[end - mid];

        // printf("Trying to take %d elements. The sum of those elements is %lld. We have %d available as food.\n", mid, sum, food);
        // printf("Need %lld\n", k * mid - sum);

        if (k * mid - sum <= food) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    // printf("Taking %d outright and %d through feeding\n", (n - end), lo);

    return (n - end) + (lo);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int q;
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", a + i);
        }
        sort(a + 1, a + n + 1);

        p[0] = 0LL;
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] + a[i];
        }

        int k;
        while (q-- > 0) {
            scanf("%d", &k);
            printf("%d\n", solve(k));
        }
    }

    return 0;
}
