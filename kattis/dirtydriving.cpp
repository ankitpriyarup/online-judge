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

bool works(const vector<ll>& p, int k, ll d) {
    // start at -d
    for (int i = 0; i < p.size(); ++i) {
        ll loc = p[i] - k * (i + 1);
        if (d > loc)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, p;
    cin >> n >> p;
    vector<ll> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
    }
    sort(begin(pos), end(pos));
    for (int i = 1; i < n; ++i) {
        pos[i] -= pos[0];
    }
    pos[0] = 0;

    ll d = 0;
    for (int i = 0; i < n; ++i) {
        ll loc = pos[i] - (i + 1) * p;
        d = min(d, loc);
    }

    cout << -d << '\n';
    
    return 0;
}
