#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

constexpr int MAXN = 1003;
int n, p;
ll s;
vector<int> graph[MAXN];
ll x[MAXN], y[MAXN];
bool vis[MAXN];

ll dist(int i, int j) {
    ll xd = x[i] - x[j];
    ll yd = y[i] - y[j];

    return xd * xd + yd * yd;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %lld", &n, &p, &s);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld %lld", x + i, y + i);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (dist(i, j) <= s * s) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    queue<int> q;
    q.push(p);
    vis[p] = true;
    ll ans = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        ans = max(ans, dist(p, cur));
        for (auto child : graph[cur]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
            }
        }
    }

    printf("%.3Lf\n", sqrt(1.0L * ans) + s);

    return 0;
}
