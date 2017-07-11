#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5003;
const int INF = (int) 1e9;

int n, max_width;
int w[MAXN], h[MAXN];

// dp[x] is the min height for values up to x
int dp[MAXN];

int main() {
    scanf("%d %d", &n, &max_width);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", w + i, h + i);
    }

    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int seg_width = 0;
        int max_h = 0;
        dp[i] = INF;

        for (int j = i; j > 0; --j) {
            seg_width += w[j];
            max_h = max(max_h, h[j]);
            if (seg_width > max_width) {
                break;
            }

            dp[i] = min(dp[i], dp[j - 1] + max_h);
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
