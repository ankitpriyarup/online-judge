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
    double w;
    cin >> n >> w;
    vector<pair<int, double>> guns(n);
    for (int i = 0; i < n; ++i) {
        cin >> guns[i].first >> guns[i].second;
    }

    sort(begin(guns), end(guns), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.first + a.second * b.first < b.first + a.first * b.second;
    });

    double cost = 0.0;
    for (int i = 0; i < n; ++i) {
        cost += w * guns[i].first;
        w *= guns[i].second;
    }

    cout << fixed << setprecision(10) << cost << '\n';

    return 0;
}
