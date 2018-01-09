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

    int tc = 1;
    int e, m;
    while (scanf("%d %d", &e, &m) == 2) {
        int ans = 0;
        while (e != 0 or m != 0) {
            ++ans;
            ++e;
            ++m;
            if (e == 365) e = 0;
            if (m == 687) m = 0;
        }
        printf("Case %d: %d\n", tc++, ans);
    }

    return 0;
}
