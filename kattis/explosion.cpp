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

map<vector<int>, double> memo;

double solve(const vector<int>& state, int d) {
    int opp_alive = 0;
    for (int i = 6; i < 12; ++i) {
        opp_alive += state[i];
    }
    if (opp_alive == 0)
        return 1.0;

    if (d == 0) {
        return 0.0;
    }

    auto it = memo.find(state);
    if (it != end(memo))
        return it->second;

    int tot_alive = opp_alive;
    for (int i = 0; i < 6; ++i) {
        tot_alive += state[i];
    }

    double res = 0.0;

    vector<int> new_state(begin(state), end(state));
    for (int i = 0; i < 12; ++i) {
        if (!state[i])
            continue;

        double prob = static_cast<double>(state[i]) / tot_alive;
        --new_state[i];
        if (i != 0 and i != 6)
            ++new_state[i - 1];

        res += prob * solve(new_state, d - 1);

        if (i != 0 and i != 6)
            --new_state[i - 1];
        ++new_state[i];
    }

    return memo[state] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, d, x;
    scanf(" %d %d %d", &n, &m, &d);
    vector<int> state(12);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &x);
        ++state[x - 1];
    }
    for (int i = 0; i < m; ++i) {
        scanf(" %d", &x);
        ++state[6 + x - 1];
    }

    printf("%.13f", solve(state, d));
    return 0;
}
