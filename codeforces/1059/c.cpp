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

void solve(int n, int scale = 1) {
    int ones = (n + 1) / 2;
    for (int i = 0; i < ones; ++i)
        cout << scale << ' ';

    if (n == 3) {
        cout << 3 * scale;
    } else if (n > 1) {
        solve(n / 2, 2 * scale);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    /*
     * 1: 1
     * 2: 1 2
     * 3: 1 1 3
     * 4: 1 1 2 4
     * 5: 1 1 1 2 4
     * 6: 1 1 1 2 2 6
     */

    int n;
    cin >> n;
    solve(n);

    return 0;
}
