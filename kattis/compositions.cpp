#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

// returns if x = m + i * k
inline bool in_sequence(int x, int m, int k) {
    return (x - m) % k == 0;
}

long long dp[40];

int main() {
    int T;
    scanf("%d", &T);

    int id, n, m, k;
    while (T-- > 0) {
        scanf("%d %d %d %d", &id, &n, &m, &k);
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                int diff = i - j;
                if (!in_sequence(diff, m, k)) {
                    dp[i] += dp[j];
                }
            }

            if (!in_sequence(i, m, k)) {
                ++dp[i];
            }
        }

        printf("%d %lld\n", id, dp[n]);
    }

    return 0;
}
