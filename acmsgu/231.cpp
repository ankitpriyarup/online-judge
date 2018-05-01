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

constexpr int MAXV = 1e6 + 66;
int n;
int sieve[MAXV];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> primes;
    for (int i = 2; i < MAXV; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = i; j < MAXV; j += i) {
                sieve[j] = i;
            }
        }
    }

    scanf(" %d", &n);
    vector<int> ans;
    for (int i = 0; i + 1 < primes.size() and primes[i + 1] <= n; ++i) {
        if (primes[i] + 2 == primes[i + 1]) {
            ans.push_back(primes[i]);
        }
    }

    printf("%lu\n", ans.size());
    for (int x : ans) {
        printf("%d %d\n", 2, x);
    }

    return 0;
}
