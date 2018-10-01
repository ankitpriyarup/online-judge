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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += n - 1;
    }

    /*
     * 3 4 10
     * 0 4 6
     * 0 1 2
     */

    /*
     * 2 5
     * 0 0
     * x
     */

    /*
     * 5 6 10 11 13
     * 0 4 10 11 13
     * 0 1 6 11 13
     * 0 1 2 8 13
     * 0 1 2 3 11
     * 0 1 2 3 4
     */

    sort(begin(a), end(a));
    int cost = 0;
    for (int i = 0; i < n; ++i) {
        cost += a[i] - i;
    }

    cout << (cost % 7 == 0 ? "yes" : "no") << '\n';

    return 0;
}
