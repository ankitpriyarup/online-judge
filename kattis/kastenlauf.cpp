#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 150;
int n;
int x[MAXN], y[MAXN];
bool vis[MAXN];

void read() {
    scanf("%d", &n);
    n += 2;

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", x + i, y + i);
    }
}

ll dist(int a, int b) {
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

void solve() {
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == n - 1) {
            break;
        }

        for (int i = 0; i < n; ++i) {
            if (!vis[i] and dist(cur, i) <= 1LL * 50 * 20) {
                vis[i] = true;
                q.push(i);
            }
        }
    }

    printf("%s\n", vis[n - 1] ? "happy" : "sad");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        read();
        solve();
    }
    
    return 0;
}
