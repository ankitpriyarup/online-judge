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

ld score(const vector<pii>& vec) {
    ld v = 0;
    ld x = 0;
    for (auto& p : vec) {
        int acc = p.first;
        int dur = p.second;

        ld new_v = v + 1.0L * dur * acc;
        ld new_x = x + v * dur + 0.5L * acc * dur * dur;

        v = new_v;
        x = new_x;
    }

    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    vector<pii> dur(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &dur[i].first, &dur[i].second);
    }

    ld dist = score(dur);
    sort(begin(dur), end(dur));
    reverse(begin(dur), end(dur));
    ld best = score(dur);

    printf("%.1Lf\n", best - dist);

    return 0;
}
