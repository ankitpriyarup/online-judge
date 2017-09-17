#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

constexpr int MAXN = 10004;
constexpr int INF = 2 * MAXN;

using func = int(const int& a, const int&b);

int n, v;
int is_and[MAXN], can_change[MAXN];
int cost[MAXN][2];

void read() {
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= (n - 1) / 2; ++i) {
        scanf("%d %d", is_and + i, can_change + i);
    }

    int x;
    for (int i = (n + 1) / 2; i <= n; ++i) {
        scanf("%d", &x);
        cost[i][x] = 0;
        cost[i][1 - x] = INF;
    }
}

int compute(int type, int a, int b) {
    if (type == 0) {
        return a | b;
    } else {
        return a & b;
    }
}

void solve(int case_num) {
    for (int i = (n + 1) / 2 - 1; i > 0; --i) {
        cost[i][0] = cost[i][1] = INF;

        for (int a = 0; a < 2; ++a) {
            for (int b = 0; b < 2; ++b) {
                int val = compute(is_and[i], a, b);
                cost[i][val] = min(cost[i][val], cost[2 * i][a] + cost[2 * i + 1][b]);

                if (can_change[i]) {
                    val = compute(1 - is_and[i], a, b);
                    cost[i][val] = min(cost[i][val], 1 + cost[2 * i][a] + cost[2 * i + 1][b]);
                }
            }
        }
    }

    if (cost[1][v] >= n) {
        printf("Case #%d: IMPOSSIBLE\n", case_num);
    } else {
        printf("Case #%d: %d\n", case_num, cost[1][v]);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        read();
        solve(i);
    }

    return 0;
}
