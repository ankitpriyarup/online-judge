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
    cin >> n;
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }

    sort(begin(xs), end(xs));
    sort(begin(ys), end(ys));
    int mid = (n - 1) >> 1;
    int mx = xs[mid];
    int my = ys[mid];

    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        ans += abs(xs[i] - mx);
        ans += abs(ys[i] - my);
    }

    cout << ans << '\n';
    return 0;
}
