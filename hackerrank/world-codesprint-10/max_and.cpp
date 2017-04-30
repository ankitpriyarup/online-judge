#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int n, k;
long long a[MAXN];
bool bad[MAXN];

int fact[MAXN];
int tcaf[MAXN];

inline int prod(int a, int b) {
    return (1LL * a * b) % MOD;
}

int modpow(int base, int exp) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp) {
            res = prod(res, cur);
        }

        cur = prod(cur, cur);
    }

    return res;
}

void gen_fact() {
    fact[0] = 1;
    tcaf[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = prod(fact[i - 1], i);
        tcaf[i] = modpow(fact[i], MOD - 2);
    }
}

int choose(int n, int k) {
    return prod(fact[n], prod(tcaf[k], tcaf[n - k]));
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }
    
    long long val = 0LL;
    for (long long bit = 60LL; bit >= 0; --bit) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!bad[i] and (a[i] & (1LL << bit))) {
                ++count;
            }
        }
        
        if (count >= k) {
            val |= (1LL << bit);
            
            for (int i = 0; i < n; ++i) {
                if ((a[i] & (1LL << bit)) == 0) {
                    bad[i] = true;
                }
            }
        }
    }
    
    int safe = n;
    for (int i = 0; i < n; ++i) {
        if (bad[i]) --safe;
    }
    
    gen_fact();
    printf("%lld\n", val);
    printf("%d\n", choose(safe, k));
    
    return 0;
}
