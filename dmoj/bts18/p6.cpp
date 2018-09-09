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

    int n, T;
    cin >> n >> T;
    vector<ll> heights(T + 2, 0);
    int l, r, a, b, c;

    vector<ll> aa(T + 2, 0);
    vector<ll> bb(T + 2, 0);
    vector<ll> cc(T + 2, 0);
    for (int i = 0; i < n; ++i) {
        cin >> l >> r >> a >> b >> c;
        ll ap = a;
        ll bp = (b -2LL * a * l);
        ll cp = 1LL * a * l * l - b * l + c;

        aa[l] += ap;
        aa[r + 1] -= ap;
        bb[l] += bp;
        bb[r + 1] -= bp;
        cc[l] += cp;
        cc[r + 1] -= cp;
    }

    ll av = 0;
    ll bv = 0;
    ll cv = 0;
    for (int j = 1; j <= T; ++j) {
        av += aa[j];
        bv += bb[j];
        cv += cc[j];

        ll h = av * j * j + bv * j + cv;
        cout << h << ' ';
    }
    
    return 0;
}
