#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef unsigned long long ull;

const int MAXN = 100005;
int n, m;
int v[MAXN];
ull prefix[MAXN];
map<int, int> inverse;

int main() {
    ios_base::sync_with_stdio(false);
    int q;
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        inverse[v[i]] = i;
    }

    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }

    /*
    for (int i = 0; i <= n; ++i) {
        printf("%llu ", prefix[i]);
    }
    puts("");
    */

    int a, b;
    while (q-- > 0) {
        scanf("%d %d", &a, &b);
        // printf("Indexes are %d %d\n", inverse[b] + 1, inverse[a]);
        ull amount = prefix[inverse[b] + 1] - prefix[inverse[a]];
        // printf("%llu\n", amount);
        if (amount >= 2ULL * m) {
            puts("Enough");
        } else {
            puts("Not enough");
        }
    }

    return 0;
}
