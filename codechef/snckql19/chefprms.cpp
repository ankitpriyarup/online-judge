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

    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i < 300; i += 2) {
        bool is_prime = true;
        for (int d = 3; is_prime and d * d <= i; d += 2) {
            is_prime &= (i % d != 0);
        }
        if (is_prime)
            primes.push_back(i);
    }

    set<int> semiprimes;
    for (int p : primes) {
        for (int q : primes) {
            if (p == q or p * q > 300) continue;
            semiprimes.insert(p * q);
        }
    }

    int T, n;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf(" %d", &n);
        bool valid = false;
        for (int x = 4; !valid and x <= n; ++x) {
            valid |= semiprimes.count(x) and semiprimes.count(n - x);
        }
        printf("%s\n", valid ? "YES" : "NO");
    }

    return 0;
}
