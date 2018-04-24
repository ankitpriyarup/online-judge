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

using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ull a = 1LL;
    ull b = 1LL;
    ull res = 0LL;
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        res += a;
        ull c = a + b;
        a = b;
        b = c;
    }

    printf("%llu\n", res);

    return 0;
}
