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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    vector<pii> cars(n);
    int pos, vel;
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &pos, &vel);
        cars[i] = {vel, pos};
    }
    sort(begin(cars), end(cars));

    set<pii> seen;
    double ans = 0.0;
    for (auto& car : cars) {
        tie(vel, pos) = car;

        // printf("Processing pos vel %d %d\n", pos, vel);

        pii by_pos = {pos, vel};
        if (seen.empty() or seen.lower_bound(by_pos) == end(seen)) {
            // printf("Never collides!\n");
            seen.insert(by_pos);
        } else {
            auto it = seen.lower_bound(by_pos);
            // printf("Collides with %d %d!\n", it->first, it->second);
            double t = static_cast<double>(it->first - pos) / (vel - it->second);
            // printf("dx / dv %d / %d = %.4lf\n", it->first - pos, vel - it->second, t);
            ans = max(ans, t);
        }
    }

    printf("%.9lf\n", ans);

    return 0;
}
