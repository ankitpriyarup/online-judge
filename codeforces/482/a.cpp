#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int n;
bool visit[MAXN];
int perm[MAXN];

int get_legit(int base, int diff) {
    if (base + diff <= n and !visit[base + diff]) {
        return base + diff;
    } else {
        return base - diff;
    }
}

int main() {
    int k;
    scanf("%d %d", &n, &k);

    memset(perm, 0, sizeof(perm));
    visit[1] = true;
    perm[1] = 1;

    int diff = n - 1;
    for (int i = 2; i <= k; ++i, --diff) {
        perm[i] = get_legit(perm[i - 1], diff);
        visit[perm[i]] = true;
    }

    for (int i = k + 1; i <= n; ++i) {
        perm[i] = get_legit(perm[i - 1], 1);
        visit[perm[i]] = true;
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", perm[i]);
    }
    puts("");

    return 0;
}
