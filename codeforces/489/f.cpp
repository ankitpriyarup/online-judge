#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int N, M, mod;
char row[505];
int col_counts[505];
long long memo[505][505];

long long f(int x, int y) {
    if (x == 0 && y == 0) {
        return 1LL;
    }
    if (memo[x][y] != -1) {
        return memo[x][y];
    }

    long long ans = 0;
    if (x >= 2) {
        long long ways = x * (x - 1) / 2;
        ways %= mod;
        ways *= f(x - 2, y + 2);
        ways %= mod;
        ans += ways;
    }

    if (x >= 1 && y >= 1) {
        long long ways = x * y;
        ways %= mod;
        ways *= f(x - 1, y);
        ways %= mod;
        ans += ways;
        ans %= mod;
    }

    if (y >= 2) {
        long long ways = y * (y - 1) / 2;
        ways %= mod;
        ways *= f(x, y - 2);
        ways %= mod;
        ans += ways;
        ans %= mod;
    }

    memo[x][y] = ans % mod;
    return memo[x][y];
}

int main() {
    cin >> N >> M >> mod;
    for (int i = 0; i < M; i++) {
        cin >> row;
        for (int j = 0; j < N; j++) {
            col_counts[j] += (row[j] == '0' ? 0 : 1);
        }
    }

    memset(memo, -1, sizeof memo);

    int x = 0;
    int y = 0;
    for (int i = 0; i < N; i++) {
        if (col_counts[i] == 0) {
            x++;
        } else if (col_counts[i] == 1) {
            y++;
        }
    }

    int ans = 0;
    cout << f(x, y) << '\n';
    return 0;
}
