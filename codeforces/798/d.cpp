#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct item {
    int ind;
    long long av, bv;
};

const int MAXN = 100005;
int n;
int a[MAXN];
int b[MAXN];

int main() {
    scanf("%d", &n);

    long long targetA = 0LL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        targetA += a[i];
    }

    long long targetB = 0LL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
        targetB += b[i];
    }

    vector<item> items;
    for (int i = 0; i < n; ++i) {
        items.push_back({i + 1, 2LL * a[i], 2LL * b[i]});
    }

    int iters = 500;
    int use = n / 2;
    ++use;

    vector<int> inds(use, 0);

    while (iters-- > 0) {
        random_shuffle(items.begin(), items.end());
        long long curA = 0LL;
        long long curB = 0LL;

        for (int i = 0; i < use; ++i) {
            curA += items[i].av;
            curB += items[i].bv;
            inds[i] = items[i].ind;
        }

        if (curA > targetA and curB > targetB) {
            break;
        }
    }

    printf("%d\n", use);
    for (int i = 0; i < use; ++i) {
        printf("%d%c", inds[i], i == use - 1 ? '\n' : ' ');
    }

    return 0;
}
