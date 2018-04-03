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

constexpr int MAXN = 5e6 + 6;
int n;
int a[MAXN];
int b[MAXN];
vector<int> primes;
int sieve[MAXN];
bool used[MAXN];

void gen_primes() {
    memset(sieve, 0, sizeof(sieve));
    for (int i = 2; i < MAXN; ++i) {
        if (!sieve[i]) {
            sieve[i] = i;
            primes.push_back(i);
            for (int j = 2 * i; j < MAXN; j += i) {
                sieve[j] = i;
            }
        }
    }
}

bool ok(int x) {
    while (x > 1) {
        int f = sieve[x];
        if (used[f]) return false;
        while (x % f == 0)
            x /= f;
    }

    return true;
}

void add(int x) {
    while (x > 1) {
        int f = sieve[x];
        used[f] = true;
        while (x % f == 0)
            x /= f;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    assert(n < MAXN);
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        assert(a[i] < MAXN);
    }

    gen_primes();
    for (int i = 0; i < n; ++i) {
        bool split = !ok(a[i]);

        if (split) {
            int val = a[i] + 1;
            while (!ok(val)) {
                ++val;
            }

            b[i] = val;
            add(val);

            val = 2;
            for (int j = i + 1; j < n; ++j) {
                while (!ok(val)) {
                    ++val;
                }

                b[j] = val;
                add(val);
            }

            break;
        }

        b[i] = a[i];
        add(a[i]);
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    cout << '\n';

    return 0;
}
