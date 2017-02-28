#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 200005;

int n;
int p[MAXN];
bool visit[MAXN];

void dfs(int x) {
    visit[x] = true;
    if (!visit[p[x]]) {
        dfs(p[x]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }

    int x;
    int par = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        par ^= x;
    }

    int comp = 0;

    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            ++comp;
            dfs(i);
        }
    }

    int ans = comp == 1 ? 0 : comp;

    printf("%d\n", ans + par);
    return 0;
}
