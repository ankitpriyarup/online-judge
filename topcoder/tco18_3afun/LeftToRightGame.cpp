#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>


using namespace std;
constexpr int MAXN = 1003;
int dd;
int pows[MAXN];
int dp[MAXN][MAXN][2];

bool solve(int idx, int cur, bool goal)  {
    printf("Solve(%d, %d, %d)\n", idx, cur, goal);
    if (idx == -1) {
        return (goal == 0) ? (cur == 0) : (cur != 0);
    }

    assert(idx >= 0);
    assert(cur < dd);

    if (dp[idx][cur][goal] != -1) {
        return dp[idx][cur][goal];
    }
    dp[idx][cur][goal] = 0;
    for (int i = 0; i <= 9; ++i) {
        int val = (cur + (1LL * i * pows[idx] % dd)) % dd;
        dp[idx][cur][goal] |= !solve(idx - 1, val, goal ^ 1);
    }

    return dp[idx][cur][goal];
}

class LeftToRightGame {
  public:
    string whoWins(int length, int divisor) {
        if (divisor == 1) {
            return "Bob";
        }
        if (length == 1) {
            return "Alice";
        }
        dd = divisor;
        memset(dp, -1, sizeof(dp));
        pows[0] = 1;
        for (int i = 1; i <= MAXN; ++i) {
            pows[i] = (1LL * pows[i - 1] * 10) % dd;
        }
        for (int i = 1; i <= 9; ++i) {
            int val = (1LL * i * pows[length - 1]) % dd;
            if (!solve(length - 2, val, 0)) {
                return "Alice";
            }
        }

        return "Bob";
    }
};

int main() {
    LeftToRightGame sub;
    string ans = sub.whoWins(4, 10);
    cout << ans << '\n';
}
