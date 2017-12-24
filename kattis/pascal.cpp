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

    ll n;
    scanf("%lld", &n);
    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (n % i == 0) {
            printf("%lld\n", n - (n / i));
            return 0;
        }
    }

    printf("%lld\n", n - 1);

    return 0;
}
