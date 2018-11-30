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

const int MAXN = 32000;
bool sieve[MAXN]; // 1 if prime, 0 if composite
vector<int> primes;

void gen_sieve() {
    sieve[2] = 0;
    for (int i = 3; i <= MAXN; i += 2) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j < MAXN; j += 2LL * i) {
                sieve[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_sieve();

    int T;
    cin >> T;
    while (T-- > 0) {
        int x;
        cin >> x;

        vector<int> ans;
        if (x == 4) {
            ans.push_back(2);
        }
        for (int p : primes) {
            if ((p << 1) > x)
                break;
            if (!sieve[x - p])
                ans.push_back(p);
        }

        cout << x << " has " << ans.size() << " representation(s)\n";
        for (int y : ans) {
            cout << y << "+" << (x - y) << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}
