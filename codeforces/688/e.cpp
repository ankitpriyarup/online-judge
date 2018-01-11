#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MAXN = 505;
int n, cap;
int a[MAXN];
bool dp[MAXN][MAXN][MAXN];

int main() {
    scanf("%d %d", &n, &cap);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    dp[0][0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= cap; ++j) {
            for (int k = 0; k <= cap; ++k) {
                dp[i + 1][j][k] |= dp[i][j][k];

                if (j + a[i] <= cap)
                    dp[i + 1][j + a[i]][k] |= dp[i][j][k];

                if (k + a[i] <= cap)
                    dp[i + 1][j][k + a[i]] |= dp[i][j][k];
            }
        }
    }

    vector<int> res;
    for (int j = 0; j <= cap; ++j) {
        if (dp[n][j][cap - j])
            res.push_back(j);
    }

    printf("%d\n", (int)res.size());
    for (int x : res)
        printf("%d ", x);
    return 0;
}
