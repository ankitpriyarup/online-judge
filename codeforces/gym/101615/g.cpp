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
int n, m, k;
int s, t;
vector<pair<int, pii> > graph[MAXN];
bool vis[MAXN];

bool bfs(int x) {
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == t) return true;
        for (auto edge : graph[cur]) {
            if (!vis[edge.first] and edge.second.first <= x and x <= edge.second.second) {
                vis[edge.first] = true;
                q.push(edge.first);
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &m, &k);
    scanf("%d %d", &s, &t);

    vector<int> ends;
    int a, b, c, d;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        graph[a].push_back({b, {c, d}});

        for (int x = -1; x <= 1; ++x) {
            ends.push_back(min(max(1, c + x), k));
            ends.push_back(min(max(1, d + x), k));
        }
    }

    ends.push_back(1);
    ends.push_back(k);
    sort(begin(ends), end(ends));
    ends.erase(unique(begin(ends), end(ends)), end(ends));

    vector<bool> valid;
    bool in_valid = false;
    int first = -1;
    int last = -1;
    int ans = 0;
    for (int x : ends) {
        int res = bfs(x);
        valid.push_back(res);

        // printf("%d %d\n", x, res);
        if (res) {
            if (!in_valid) {
                in_valid = true;
                first = last = x;
            } else {
                last = x;
            }
        } else {
            if (in_valid) {
                in_valid = false;
                ans += (last - first + 1);
            }
        }
    }

    if (in_valid) {
        ans += (k - first + 1);
    }

    printf("%d\n", ans);
    
    return 0;
}
