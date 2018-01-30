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
using seg = tuple<int, int, int, int>;

constexpr int MAXN = 50004;
int n;
vector<int> graph[MAXN];
ll areas[MAXN];
bool vis[MAXN];

bool overlap(const seg& aa, const seg& bb) {
    int a = get<1>(aa);
    int b = get<2>(aa);
    int c = get<1>(bb);
    int d = get<2>(bb);

    return (a <= c and c <= b)
        or (c <= a and a <= d);
}

void process(const vector<seg>& begins, const vector<seg>& ends) {
    int p1 = 0;
    int p2 = 0;

    for (const seg& s : begins) {
        int x = get<0>(s);

        while (p1 < ends.size() and get<0>(ends[p1]) < x) {
            ++p1;
        }

        p2 = max(p2, p1 + 1);

        while (p2 < ends.size() and get<0>(ends[p2]) == get<0>(ends[p1])) {
            ++p2;
        }

        if (p1 < ends.size() and get<0>(ends[p1]) == x) {
            for (int i = p1; i < p2; ++i) {
                if (overlap(s, ends[i])) {
                    int u = get<3>(s);
                    int v = get<3>(ends[i]);
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }
    }
}

ll dfs(int u) {
    if (vis[u])
        return 0LL;

    vis[u] = true;
    ll res = areas[u];
    for (int v : graph[u]) {
        res += dfs(v);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int x, y, w, h;
    vector<seg> begin_x, end_x, begin_y, end_y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &x, &y, &w, &h);
        begin_x.push_back(make_tuple(x, y, y + h, i));
        end_x.push_back(make_tuple(x + w, y, y + h, i));

        begin_y.push_back(make_tuple(y, x, x + w, i));
        end_y.push_back(make_tuple(y + h, x, x + w, i));

        areas[i] = 1LL * w * h;
    }

    sort(begin(begin_x), end(begin_x));
    sort(begin(end_x), end(end_x));
    sort(begin(begin_y), end(begin_y));
    sort(begin(end_y), end(end_y));

    process(begin_x, end_x);
    process(begin_y, end_y);

    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dfs(i));
    }

    printf("%lld\n", ans);

    return 0;
}
