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

constexpr int MAXN = 5003;

int n, max_h;
ll score[MAXN];
ll score2[MAXN];
ll g[MAXN], q[MAXN];
int h[MAXN], t[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &max_h);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %d %lld %d", g + i, h + i, q + i, t + i);
    }

    for (int i = 0; i < n; ++i) {
        // force taking the first part in score2
        for (int time = 0; time <= max_h; ++time) {
            score2[time] = time < h[i] ? 0 : g[i] + score[time - h[i]];
        }

        // now do infinite knapsack on the rest
        for (int time = h[i]; time + t[i] <= max_h; ++time) {
            score2[time + t[i]] = max(score2[time + t[i]], q[i] + score2[time]);
        }

        // merge
        for (int time = 0; time <= max_h; ++time) {
            score[time] = max(score[time], score2[time]);
        }
    }

    printf("%lld\n", score[max_h]);

    return 0;
}
