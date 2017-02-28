#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 1000006;
const int MAXS = 61;

map<long long, int> memo[MAXS];

int n;
int a[MAXN];

int grundy(int left, long long bitmask) {
    if (left == 0) {
        return 0;
    }

    if (memo[left].find(bitmask) != memo[left].end()) {
        return memo[left][bitmask];
    }

    set<int> seen;
    for (int take = 1; take <= left; ++take) {
        long long bit = 1LL << take;
        if ((bitmask & bit) == 0) {
            seen.insert(grundy(left - take, bitmask | bit));
        }
    }

    int res = 0;
    while (seen.find(res) != seen.end()) {
        ++res;
    }

    return memo[left][bitmask] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans ^= grundy(a[i], 0);
    }

    if (ans) {
        puts("NO");
    } else {
        puts("YES");
    }
    return 0;
}
