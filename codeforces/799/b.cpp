#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <complex>

using namespace std;

const int MAXN = 200005;
int n;
int p[MAXN];
int a[MAXN];
int b[MAXN];
bool used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", p + i);
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq[3];

    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        --a[i];
        pq[a[i]].push({p[i], i});
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
        --b[i];
        pq[b[i]].push({p[i], i});
    }

    int m;
    scanf("%d", &m);
    int c;
    memset(used, 0, sizeof(used));
    for (int i = 0; i < m; ++i) {
        int ans = -1;
        scanf("%d", &c);
        --c;
        if (!pq[c].empty()) {
            int ind = pq[c].top().second;
            pq[c].pop();
            ans = p[ind];
            used[ind] = true;

            for (int j = 0; j < 3; ++j) {
                while (!pq[j].empty() and used[pq[j].top().second]) {
                    pq[j].pop();
                }
            }
        }

        printf("%d%c", ans, i == m - 1 ? '\n' : ' ');
    }

    return 0;
}
