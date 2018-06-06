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

constexpr int MAXN = 10004;

template<int CAP>
struct sieve {
    vector<int> primes;
    bool comp[CAP];

    sieve() {
        memset(comp, 0, sizeof(comp));
        primes.push_back(2);
        for (int d = 3; d < CAP; d += 2) {
            if (!comp[d]) {
                primes.push_back(d);
                for (int j = d; j < CAP; j += 2 * d)
                    comp[j] = true;
            }
        }
    }
};

int main() {
    sieve<MAXN> s;
    vector<int> superprimes;
    for (int p : s.primes) {
        if (p - 1 >= s.primes.size())
            break;
        superprimes.push_back(s.primes[p - 1]);
    }

    int n;
    scanf(" %d", &n);
    vector<int> dp(n + 1, MAXN);
    vector<int> last(n + 1, -1);
    dp[0] = 0;

    for (int p : superprimes) {
        for (int i = p; i <= n; ++i) {
            if (dp[i - p] + 1 < dp[i]) {
                dp[i] = dp[i - p] + 1;
                last[i] = p;
            }
        }
    }

    if (dp[n] == MAXN) {
        printf("%d\n", 0);
    } else {
        printf("%d\n", dp[n]);
        int cur = n;
        while (cur) {
            printf("%d ", last[cur]);
            cur -= last[cur];
        }
        printf("\n");
    }

    return 0;
}
