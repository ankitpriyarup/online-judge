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

    int T;
    scanf(" %d", &T);
    uint32_t a, b, d;
    while (T-- > 0) {
        scanf(" %u %u %u", &a, &b, &d);

        // You can either +a, +b, -a, or -b
        // Therefore you can make any ax + by
        // thus gcd(a, b) | d
        printf("%s\n", d % __gcd(a, b) == 0 ? "Yes" : "No");
    }
    
    return 0;
}
