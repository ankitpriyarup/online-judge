#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("fraction.in", "r", stdin);
    freopen("fraction.out", "w", stdout);

    int n;
    scanf("%d", &n);
    int ans = 0;

    for (int a = 1; a <= (n - a); ++a) {
        if (gcd(a, n - a) == 1)
            ans = a;
    }
    printf("%d %d\n", ans, n - ans);
    
    return 0;
}
