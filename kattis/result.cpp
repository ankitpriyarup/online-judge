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

using ll = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 102;
constexpr ll INF = numeric_limits<ll>::max();

int n;
int ptr;
ll dp[2][MAXN][MAXN];
char buf[MAXN * MAXN];
ll nums[MAXN];
char ops[MAXN];

void parse_num() {
    ll res = 0LL;
    while ('0' <= buf[ptr] and buf[ptr] <= '9') {
        res *= 10LL;
        res += (buf[ptr++] - '0');
    }

    nums[n++] = res;
}

void parse() {
    int len = strlen(buf);

    n = 0;
    ptr = 0;
    parse_num();
    while (ptr < len) {
        ops[n] = buf[ptr++];
        parse_num();
    }
}

ll solve(int k, int i, int j) {
    if (dp[k][i][j] != -1)
        return dp[k][i][j];

    if (i + 1 == j) {
        return dp[k][i][j] = nums[i];
    }

    ll ret = k ? 0 : INF;
    for (int l = i + 1; l < j; ++l) {
        ll lefts[] = {solve(0, i, l), solve(1, i, l)};
        ll rights[] = {solve(0, l, j), solve(1, l, j)};

        for (int kk1 = 0; kk1 <= 1; ++kk1) {
            for (int kk2 = 0; kk2 <= 1; ++kk2) {
                ll cur;
                if (ops[l] == '+')
                    cur = lefts[kk1] + rights[kk2];
                else
                    cur = lefts[kk1] * rights[kk2];

                if (k)
                    ret = max(ret, cur);
                else
                    ret = min(ret, cur);
            }
        }
    }

    return dp[k][i][j] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf("%s", buf) == 1) {
        if (!strcmp(buf, "END")) break;

        parse();
        memset(dp, -1, sizeof(dp));
        printf("%llu %llu\n", solve(0, 0, n), solve(1, 0, n));
    }

    return 0;
}
