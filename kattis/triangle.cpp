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

    // s_0 = 1
    // t_0 = 1
    // for each step, s_n /= 2, t_n *= 3
    // circumference = 3 * s_n * t_n
    //
    // circumference = 3^(n + 1) / 2^n
    // log(circum) = (n + 1) * log(3) - n * log(2) 

    int n;
    int tc = 1;
    while (scanf("%d", &n) == 1) {
        double res = ceil((n + 1.0) * log10(3) - 1.0 * n * log10(2));
        printf("Case %d: %d\n", tc++, static_cast<int>(res + 0.4));
    }

    return 0;
}
