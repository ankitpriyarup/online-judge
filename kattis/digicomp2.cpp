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

constexpr int MAXN = 500005;
int n;
int in_deg[MAXN];
int l[MAXN], r[MAXN];
bool state[MAXN];
ll balls[MAXN];

char res[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll start;
    scanf("%lld %d", &start, &n);
    char buf[10];
    for (int i = 1; i <= n; ++i) {
        scanf("%s %d %d", buf, l + i, r + i);
        ++in_deg[l[i]];
        ++in_deg[r[i]];
        state[i] = buf[0] == 'R';
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_deg[i] == 0)
            q.push(i);
    }

    balls[q.front()] = start;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ll half = balls[u] / 2;
        balls[l[u]] += half;
        balls[r[u]] += half;
        if (balls[u] & 1) {
            if (state[u]) {
                ++balls[r[u]];
            } else {
                ++balls[l[u]];
            }

            state[u] = !state[u];
        }

        if (--in_deg[l[u]] == 0)
            q.push(l[u]);

        if (--in_deg[r[u]] == 0)
            q.push(r[u]);
    }

    for (int i = 1; i <= n; ++i) {
        res[i - 1] = "LR"[state[i]];
    }
    res[n] = '\0';
    printf("%s\n", res);

    return 0;
}
