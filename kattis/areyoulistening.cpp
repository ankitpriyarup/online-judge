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

    int cx, cy, n;
    cin >> cx >> cy >> n;
    vector<double> vd(n);
    int x, y, r;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> r;
        int dx = x - cx;
        int dy = y - cy;
        double dist = sqrt(dx * dx + dy * dy) - r;
        vd[i] = dist;
    }
    sort(begin(vd), end(vd));
    int ans = (int)vd[2];
    printf("%d\n", max(0, ans));
    
    return 0;
}
