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

int f(int x) {
    int ans = 0;

    for (int p = 5; p <= x; p *= 5) {
        ans += x / p;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    int lo = 0;
    int hi = 2e9;
    while (lo + 1 < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (f(mid) >= n)
            hi = mid;
        else
            lo = mid;
    }

    if (f(hi) == n)
        printf("%d\n", hi);
    else
        printf("No solution\n");
    
    return 0;
}
