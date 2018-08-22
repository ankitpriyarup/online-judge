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

bool is_happy(int x) {
    if (x == 1) {
        return true;
    }
    if (x == 89) {
        return false;
    }

    int d = 0;
    while (x) {
        int v = x % 10;
        d += v * v;
        x /= 10;
    }

    return is_happy(d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    constexpr int MAXM = 10000;
    vector<char> is_prime(MAXM + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int x = 4; x <= MAXM; x += 2) {
        is_prime[x] = false;
    }

    for (int d = 3; d <= MAXM; d += 2) {
        if (is_prime[d]) {
            for (ll j = 1LL * d * d; j <= MAXM; j += 2LL * d) {
                is_prime[j] = false;
            }
        }
    }

    int T;
    cin >> T;
    int k, v;
    while (T-- > 0) {
        cin >> k >> v;
        bool prime = is_prime[v];
        bool happy = is_happy(v);
        cout << k << ' ' << v << ' ' << (happy and prime ? "YES" : "NO") << '\n';
    }

    
    return 0;
}
