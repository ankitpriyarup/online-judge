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

    if (n < 6) {
        // incorrect answer
        cout << -1 << '\n';
    } else {
        cout << 1 << ' ' << 2 << '\n';
        for (int i = 3; i <= n; ++i) {
            if (i % 2) {
                cout << 1 << ' ' << i << '\n';
            } else {
                cout << 2 << ' ' << i << '\n';
            }
        }
    }

    // correct answer
    for (int i = 2; i <= n; ++i) {
        cout << 1 << ' ' << i << '\n';
    }

    return 0;
}
