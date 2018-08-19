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

int f(int dice) {
    if (dice == 1) {
        return 20;
    } else {
        return 20 * 2 + 14 * (dice - 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    if (n == 21) {
        printf("%d\n", 1);
        return 0;
    }

    int lo = 1;
    int hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        int dots = f(mid);
        if (dots >= n) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    int dots = f(hi);
    if (n + 10 >= dots) {
        printf("%d\n", hi);
    } else {
        printf("%d\n", -1);
    }
    
    return 0;
}
