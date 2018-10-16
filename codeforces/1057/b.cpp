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
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int lo = 0;
    int hi = n + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        int goal = 100 * mid;
        int cur = 0;
        for (int i = 0; i < mid; ++i) {
            cur += v[i];
        }
        bool poss = false;
        poss |= cur > goal;
        for (int i = mid; i < n; ++i) {
            cur -= v[i - mid];
            cur += v[i];
            poss |= cur > goal;
        }

        if (poss) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << '\n';

    return 0;
}
