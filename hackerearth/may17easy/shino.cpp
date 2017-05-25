#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1000000007;
int b[5];

inline int sum(const int& a, const int& b) {
    return (0LL + a + b) % MOD;
}

inline int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}

int memo[(int)1e6][5];

int solve(vector<int> times, int skip) {
    bool all_zero = true;
    for (int x : times)
        all_zero &= (x == 0);

    if (all_zero) return 1;

    int hash = 0;
    for (int i = 0; i < 5; ++i) {
        hash *= 11;
        hash += times[i];
    }

    if (skip >= 0 and memo[hash][skip] != -1) {
        return memo[hash][skip];
    }

    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        if (i == skip) continue;

        int ways = 0;
        for (int j = 1; j <= min(times[i], b[i]); ++j) {
            times[i] -= j;
            ways = sum(ways, solve(times, i));
            times[i] += j;
        }

        ans = sum(ans, ways);
    }

    if (skip >= 0) {
        memo[hash][skip] = ans;
    }

    return ans;
}

int main() {
    vector<int> a;

    int x;
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &x);
        a.push_back(x);
    }

    for (int i = 0; i < 5; ++i) {
        scanf("%d", b + i);
    }

    memset(memo, -1, sizeof(memo));
    printf("%d\n", solve(a, -1));

    return 0;
}
