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

constexpr int MAXN = 1e6 + 6;
int sieve[MAXN];

void gen_sieve() {
    memset(sieve, -1, sizeof(sieve));
    for (int i = 2; i < MAXN; i += 2) {
        sieve[i] = i;
    }
    for (int i = 3; i < MAXN; i += 2)
        if (sieve[i] == -1)
            for (int j = i; j < MAXN; j += i)
                sieve[j] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_sieve();

    int T;
    scanf("%d", &T);
    int n, e;
    while (T-- > 0) {
        scanf("%d %d", &n, &e);
        int p = sieve[n];
        int q = n / sieve[n];

        int pn = (p - 1) * (q - 1);
        int d;
        for (d = 1; (1LL * d * e) % pn != 1; ++d);

        printf("%d\n", d);
    }
    
    return 0;
}
