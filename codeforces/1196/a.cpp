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
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while (q-- > 0) {
        vector<ll> a(3);
        for (int k = 0; k < 3; ++k)
            cin >> a[k];

        sort(begin(a), end(a));
        ll alice = a[1];
        ll bob = a[0];
        ll take = min(alice - bob, a[2]);
        bob += take;
        a[2] -= take;

        ll res = alice + (a[2] / 2);
        cout << res << '\n';
    }

    return 0;
}
