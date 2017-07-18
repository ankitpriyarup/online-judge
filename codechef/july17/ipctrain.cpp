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

const int MAXN = 100005;
int n, d;

vector<pair<int, int> > starts[MAXN];

long long ans;

void read() {
    scanf("%d %d", &n, &d);

    for (int i = 1; i <= d; ++i) {
        starts[i].clear();
    }

    ans = 0LL;

    int start, cap, sad;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &start, &cap, &sad);

        starts[start].push_back({sad, cap});
        ans += 1LL * cap * sad;
    }
}

void solve() {
    priority_queue<pair<int, int> > pq;
    for (int i = 1; i <= d; ++i) {
        for (pair<int, int> teacher : starts[i]) {
            pq.push(teacher);
        }

        if (pq.empty()) {
            continue;
        }

        pair<int, int> best = pq.top();
        pq.pop();
        ans -= best.first;
        // printf("On day %d using teacher with sadness %d\n", i, best.first);

        if (best.second > 1) {
            pq.push({best.first, best.second - 1});
        }
    }

    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        read();
        solve();
    }

    return 0;
}
