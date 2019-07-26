#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 9;
int sum(int a, int b, int mod=MOD) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }

    return c;
}

inline int prod(int a, int b, int mod=MOD) {
    return (1LL * a * b) % mod;
}

int modpow(int base, int exp, int mod=MOD) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp) {
            res = prod(res, cur, mod);
        }

        cur = prod(cur, cur, mod);
    }

    return res;
}

inline int inv(int x, int mod=MOD) {
    return modpow(x, mod - 2, mod);
}

int query(int l, int r) {
    cout << "? " << (l + 1) << ' ' << (r + 1) << endl;
    cout.flush();

    int x;
    cin >> x;
    return x;
}

constexpr int MAXN = 1e4 + 4;
int sieve[MAXN];
vector<int> primes, inv_primes;

void gen_sieve() {
    for (int i = 2; i < MAXN; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            inv_primes.push_back(inv(i));
            for (int j = i; j < MAXN; j += i) {
                sieve[j] = i;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vi ans(n);

    gen_sieve();

    int m = primes.size();
    int last = 1;
    for (int i = 1; i < n; i += 2) {
        int cur = query(0, i);
        int pair = prod(cur, inv(last));
        last = cur;

        for (int j = 0; j < m; ++j) {
            int q = prod(pair, inv_primes[j]);
            if (q < MAXN and sieve[q] == q) { 
                int p = primes[j];
                ans[i - 1] = min(p, q);
                ans[i] = max(p, q);
                break;
            }
        }
    }

    if (n % 2 == 1) {
        ans[n - 1] = prod(query(0, n - 1), inv(last));
    }

    cout << "!";
    for (int x : ans) {
        cout << ' ' << x;
    }
    cout << endl;
    cout.flush();
    
    return 0;
}
