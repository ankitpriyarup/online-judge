#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 1000000;
long long tree[MAXN + 6];

long long get(int idx) {
    long long sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

void update(int idx) {
    while (idx <= MAXN) {
        tree[idx]++;
        idx += (idx & -idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
    scanf("%d %d", &n, &k);

    k = min(k, n - k);

    int start = 0;
    int end = k;

    long long ans = 1;
    memset(tree, 0, sizeof(tree));
    for (int xxx = 0; xxx < n; ++xxx) {
        // count the number of lines coming out between start and end
        ans += 1;
        if (start < end) {
            ans += get(end);
            ans -= get(start + 1);
        } else {
            long long lines = 2LL * xxx;
            lines -= get(start + 1);
            lines += get(end);
            ans += lines;
        }

        printf("%lld ", ans);

        update(start + 1);
        update(end + 1);

        start += k;
        end += k;
        start %= n;
        end %= n;
    }

    printf("\n");

    return 0;
}
