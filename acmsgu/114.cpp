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

double score(const vector<pair<int, int>>& v, double d) {
    double res = 0.0;
    for (auto& p : v) {
        double dist = abs(p.first - d);
        res += dist * p.second;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    int tot_left = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        tot_left += v[i].second;
    }

    sort(begin(v), end(v));

    int goal = (tot_left + 1) / 2;

    while (tot_left - v.back().second >= goal) {
        tot_left -= v.back().second;
        v.pop_back();
    }

    cout << v.back().first << '\n';

    return 0;
}
