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

constexpr int MAXV = 64000;
vector<int> primes;
bool sieve[MAXV];

int solve(int n) {
    if (n < 0) {
        return -1;
    }

    // smallest factor of n >= 4
    for (int x = 4; x <= 100; ++x) {
        if (n % x == 0) {
            return x;
        }
    }

    for (int p : primes) {
        if (n % p == 0) {
            return p;
        }
    }

    int ans = n;
    if (n % 2 == 0 and n / 2 >= 4) {
        ans = min(ans, n / 2);
    }
    if (n % 3 == 0 and n / 3 >= 4) {
        ans = min(ans, n / 3);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int d = 6; d + 1< MAXV; d += 6) {
        for (int x = -1; x <= 1; x += 2) {
            int v = d + x;
            if (!sieve[v]) {
                primes.push_back(v);
                for (int j = v; j < MAXV; j += v) {
                    sieve[j] = true;
                }
            }
        }
    }

    int n;
    while (scanf(" %d", &n) == 1) {
        if (!n) break;
        int ans = solve(n - 3);
        if (ans < 4) {
            printf("No such base\n");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
