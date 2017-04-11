#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 16;
const long long oo = 1e18;
int n, k;

// width, height, quantity
long long w[MAXN], h[MAXN], q[MAXN];

long long dp[2][1 << MAXN];
long long single[1 << MAXN];

inline bool has_bit(int mask, int ind) {
    return (mask & (1 << ind)) > 0;
}

long long compute(int mask) {
    long long max_width = 0LL;
    long long max_height = 0LL;

    for (int i = 0; i < n; ++i) {
        if (has_bit(mask, i)) {
            max_width = max(max_width, w[i]);
            max_height = max(max_height, h[i]);
        }
    }

    long long area = max_width * max_height;
    long long extra = 0LL;

    for (int i = 0; i < n; ++i) {
        if (has_bit(mask, i)) {
            long long card_area = w[i] * h[i];
            extra += (area - card_area) * q[i];
        }
    }

    return extra;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", w + i, h + i, q + i);
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        single[mask] = compute(mask);

        dp[0][mask] = single[mask];
        dp[1][mask] = oo;
    }

    int x = 1;
    for (int i = 2; i <= k; ++i) {
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                dp[x][mask] = min(dp[x][mask], dp[x ^ 1][mask & ~submask] + single[submask]);
            }
        }

        x ^= 1;
    }

    printf("%lld\n", dp[x ^ 1][(1 << n) - 1]);

    return 0;
}
