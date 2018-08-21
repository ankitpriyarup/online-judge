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

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1003;
int n;

template <int MAX>
struct Combo {
    int fact[MAX], tcaf[MAX];

    int modpow(int base, int exp) const {
        int res = 1;
        int cur = base;
        for (int p = 1; p <= exp; p <<= 1) {
            if (exp & p)
                res = 1LL * res * cur % MOD;
            cur = 1LL * cur * cur % MOD;
        }
        return res;
    }

    inline int inv(int x) const {
        return modpow(x, MOD - 2);
    }

    Combo() {
        fact[0] = 1;
        for (int i = 1; i < MAX; ++i)
            fact[i] = (1LL * fact[i - 1] * i) % MOD;

        tcaf[MAX - 1] = inv(fact[MAXN - 1]);
        for (int i = MAX - 2; i >= 0; --i) {
            tcaf[i] = 1LL * tcaf[i + 1] * (i + 1) % MOD;
        }
    }

    int ncr(int n, int k) const {
        if (n < 0 or k < 0 or k > n) {
            return 0;
        }

        int res = 1LL * tcaf[k] * tcaf[n - k] % MOD;
        return 1LL * res * fact[n] % MOD;
    }
};

Combo<MAXN> combo;

void add_digs(vector<int>& freq, int x) {
    while (x) {
        ++freq[x % 10];
        x /= 10;
    }
}

inline int sum(int a, int b) {
    int c = a + b;
    return c >= MOD ? c - MOD : c;
}

int score(const vector<int>& freq, const vector<int>& digfreq) {
    for (int i = 0; i < 10; ++i) {
        if (freq[i])
            return 0;
    }

    int res = 1;
    int tot = 0;
    for (int i = 1; i <= 26; ++i) {
        int x = digfreq[i];
        res = 1LL * res * combo.tcaf[x] % MOD;
        tot += x;
    }

    res = 1LL * res * combo.fact[tot] % MOD;
    return res;
}

int solve(vector<int>& freq, vector<int>& digfreq, int dig) {
    if (dig == 0) {
        return score(freq, digfreq);
    }

    if (dig >= 10) {
        int a = dig / 10;
        int b = dig % 10;
        int cap = (a == b) ? freq[a] / 2 : min(freq[a], freq[b]);
        int ans = 0;
        for (int take = 0; take <= cap; ++take) {
            freq[a] -= take;
            freq[b] -= take;
            digfreq[dig] += take;

            ans = sum(ans, solve(freq, digfreq, dig - 1));

            digfreq[dig] -= take;
            freq[b] += take;
            freq[a] += take;
        }

        return ans;
    } else {
        int cap = freq[dig];
        int ans = 0;
        for (int take = 0; take <= cap; ++take) {
            freq[dig] -= take;
            digfreq[dig] += take;

            ans = sum(ans, solve(freq, digfreq, dig - 1));

            digfreq[dig] -= take;
            freq[dig] += take;
        }

        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf(" %d", &n) == 1) {
        vector<int> freq(10, 0);
        for (int d = 2; d * d <= n; ++d) {
            while (n % d == 0) {
                add_digs(freq, d);
                n /= d;
            }
        }

        if (n > 1) {
            add_digs(freq, n);
        }

        vector<int> digfreq(27, 0);
        printf("%d\n", solve(freq, digfreq, 26));
    }

    return 0;
}
