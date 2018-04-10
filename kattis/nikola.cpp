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

constexpr int MAXN = 1003;
constexpr ll INF = 1e18;
int n;
int entry[MAXN];
ll dist[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &entry[i]);
    }

    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            dist[i][j] = INF;
        }
    }

    using state = pair<ll, pii>;
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.emplace(0, make_pair(1, 0));
    dist[1][0] = 0LL;

    ll cur_dist;
    pii pos;
    ll ans = INF;
    while (!pq.empty()) {
        tie(cur_dist, pos) = pq.top();
        pq.pop();

        if (dist[pos.first][pos.second] != cur_dist)
            continue;

        if (pos.first == n)
            ans = min(ans, cur_dist);

        // forwards
        if (pos.first + pos.second + 1 <= n) {
            int idx = pos.first + pos.second + 1;
            ll new_dist = cur_dist + entry[idx];
            if (new_dist < dist[idx][pos.second + 1]) {
                dist[idx][pos.second + 1] = new_dist;
                pq.emplace(new_dist, make_pair(idx, pos.second + 1));
            }
        }

        if (pos.first - pos.second >= 1) {
            int idx = pos.first - pos.second;
            ll new_dist = cur_dist + entry[idx];
            if (new_dist < dist[idx][pos.second]) {
                dist[idx][pos.second] = new_dist;
                pq.emplace(new_dist, make_pair(idx, pos.second));
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
