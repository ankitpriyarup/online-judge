#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 102;
const int MAXP = 10000;

int n;
int target;

int price[MAXN];
// min number of coins to make this cost
int dp[MAXN][MAXP + 4];

void set(int i, int j, int v) {
    if (dp[i][j] == -1) {
        dp[i][j] = v;
    } else {
        dp[i][j] = min(dp[i][j], v);
    }
}

int main() {
    int num_cases;
    cin >> num_cases;
    while (num_cases-- > 0) {
        cin >> target >> n;
        for (int i = 0; i < n; ++i) {
            cin >> price[i];
        }

        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= MAXP; ++j) {
                if (dp[i][j] > -1) {
                    set(i + 1, j, dp[i][j]);

                    if (j + price[i] <= MAXP) {
                        set(i + 1, j + price[i], dp[i][j] + 1);
                    }
                }
            }
        }

        int best_cost = 1e9;
        int coins_used = -1;
        for (int j = target; j <= MAXP; ++j) {
            if (dp[n][j] > 0 and j < best_cost) {
                best_cost = j;
                coins_used = dp[n][j];
                break;
            }
        }

        cout << best_cost << ' ' << coins_used << '\n';
    }
    return 0;
}
