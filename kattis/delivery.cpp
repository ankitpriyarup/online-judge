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

int k;

int solve(vector<pii>& pts) {
    int dist = 0;

    while (!pts.empty()) {
        int d = pts.back().first;
        int times = pts.back().second / k;
        pts.back().second %= k;
        dist += 2 * times * d;

        if (pts.back().second == 0) {
            pts.pop_back();
            continue;
        }

        int cur = k;
        dist += 2 * d;
        while (!pts.empty() and cur > 0) {
            int dep = min(cur, pts.back().second);
            pts.back().second -= dep;
            if (pts.back().second == 0) {
                pts.pop_back();
            }

            cur -= dep;
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d %d", &n, &k);
    vector<pii> pos, neg;
    int x, t;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &t);
        if (x < 0) {
            neg.push_back({-x, t});
        } else {
            pos.push_back({x, t});
        }
    }

    sort(begin(pos), end(pos));
    sort(begin(neg), end(neg));
    int res = solve(pos) + solve(neg);

    printf("%d\n", res);

    return 0;
}
