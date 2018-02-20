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

constexpr int MAXN = 6;
int n;
int caps[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &caps[i]);
    }
    int target;
    scanf("%d", &target);

    vector<int> v(n, 0);
    v[0] = caps[0];

    map<vector<int>, int> dist;
    dist[v] = 0;

    priority_queue<pair<int, vector<int> >, vector<pair<int, vector<int> > >, greater<pair<int, vector<int> > > > pq;
    pq.push({dist[v], v});

    int d;
    vector<int> w;
    int ans = -1;
    while (!pq.empty()) {
        tie(d, w) = pq.top();
        pq.pop();
        if (dist[w] != d)
            continue;

        if (w[0] == target) {
            ans = d;
            break;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (w[i] == 0) continue;
                if (w[j] == caps[j]) continue;

                // pour from w[i] to w[j]
                int poured = min(caps[j] - w[j], w[i]);
                w[i] -= poured;
                w[j] += poured;

                int new_dist = d + poured;
                if (dist.find(w) == end(dist) or new_dist < dist[w]) {
                    dist[w] = new_dist;
                    pq.push({new_dist, w});
                }

                w[i] += poured;
                w[j] -= poured;
            }
        }
    }

    if (ans == -1)
        printf("impossible\n");
    else
        printf("%d\n", ans); 
    return 0;
}
