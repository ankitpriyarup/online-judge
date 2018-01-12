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
    ld s = 0.0L;
    ll x;
    while (n--) {
        cin >> x;
        s += x;
    }

    if (s >= 0) {
        unsigned long long t = static_cast<unsigned long long>(s);
        cout << t << '\n';
    } else {
        unsigned long long t = static_cast<unsigned long long>(-s);
        cout << "-" << t << '\n';
    }

    return 0;
}
