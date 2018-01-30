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

constexpr int MAXN = 100005;
int k;
// value mod k, last digit = sum of digits
int dist[MAXN][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &k);
    deque<pii> q;
    memset(dist, -1, sizeof(dist));
    dist[1][1] = 1;
    q.push_back({1, 1});

    while (!q.empty()) {
        pii x = q.front();
        q.pop_front();

        // multiply by 10
        int by_ten = (x.first * 10) % k;
        if (dist[by_ten][0] == -1) {
            dist[by_ten][0] = dist[x.first][x.second];
            q.push_front({by_ten, 0});
        }

        int add_one = (x.first + 1) % k;
        if (x.second + 1 < 10 and dist[add_one][x.second + 1] == -1) {
            dist[add_one][x.second + 1] = dist[x.first][x.second] + 1;
            q.push_back({add_one, x.second + 1});
        }
    }

    int res = 987654321;
    for (int i = 0; i < 10; ++i) {
        if (dist[0][i] == -1) continue;
        res = min(res, dist[0][i]);
    }

    printf("%d\n", res);

    return 0;
}
