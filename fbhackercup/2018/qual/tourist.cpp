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

void solve() {
    int n, k;
    ll v;
    cin >> n >> k >> v;
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    vector<int> res(k);
    int src = static_cast<int>(((v - 1LL) * k) % n);
    for (int d = 0; d < k; ++d) {
        res[d] = (src + d) % n;
    }
    sort(begin(res), end(res));
    for (int x : res) {
        cout << " " << names[x];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ":";
        solve();
    }

    return 0;
}
