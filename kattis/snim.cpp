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

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXS = 10004;
int k;
int a[102];
int dp[MAXS];

void precomp() {
    dp[0] = 0;
    for (int i = 1; i < MAXS; ++i) {
        set<int> s;
        for (int j = 0; j < k; ++j)
            if (a[j] <= i)
                s.insert(dp[i - a[j]]);

        while (s.find(dp[i]) != end(s))
            ++dp[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
        scanf("%d", a + i);

    precomp();

    int q;
    scanf("%d", &q);
    int n, x;
    while (q-- > 0) {
        scanf("%d", &n);
        int res = 0;
        while (n-- > 0) {
            scanf("%d", &x);
            res ^= dp[x];
        }

        printf("%c", res == 0 ? 'L' : 'W');
    }
    printf("\n");
    
    return 0;
}
