#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAXN = 5003;
struct env {
    int w, h, id;
    bool operator<(const env& other) const {
        return w < other.w;
    }
} v[MAXN];

int n;
int dp[MAXN];
int follow[MAXN];

int main() {
    scanf("%d %d %d", &n, &v[0].w, &v[0].h);
    v[0].id = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &v[i].w, &v[i].h);
        v[i].id = i;
    }

    sort(v, v + n + 1);

    int start = 0;
    for (int i = n; i >= 0; --i) {
        if (v[i].id == 0)
            start = i;

        dp[i] = 1;
        follow[i] = n + 1;
        for (int j = i + 1; j <= n; ++j) {
            if (v[i].w < v[j].w and v[i].h < v[j].h and 1 + dp[j] > dp[i]) {
                dp[i] = 1 + dp[j];
                follow[i] = j;
            }
        }
    }

    /*
    for (int i = 0; i <= n; ++i)
        printf("%d %d (%d) | %d\n", v[i].w, v[i].h, v[i].id, dp[i]);
    */

    printf("%d\n", dp[start] - 1);
    int card = follow[start];
    while (card <= n) {
        printf("%d ", v[card].id);
        card = follow[card];
    }

    printf("\n");
    return 0;
}
