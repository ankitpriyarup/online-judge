#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int table[] = {0, 1, 2, 9, 1 << 18};

inline int sum(const int& a, const int& b, const int& mod) {
    int c = a + b;
    if (c >= mod) 
        c -= mod;

    return c;
}

inline int prod(const int& a, const int& b, const int& mod) {
    return (1LL * a * b) % mod;
}

int modpow(const int& base, const int& exp, const int& mod) {
    int cur = base;
    int res = 1;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp) {
            res = prod(res, cur, mod);
        }

        cur = prod(cur, cur, mod);
    }

    return res;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void factor(int m, vector<pair<int, int> >& factors) {
    int two_count = 0;
    while ((m & 1) == 0) {
        ++two_count;
        m >>= 1;
    }

    if (two_count) {
        factors.push_back(make_pair(2, two_count));
    }

    for (int fact = 3; 1LL * fact * fact <= m; fact += 2) {
        int fact_count = 0;
        while (m % fact == 0) {
            ++fact_count;
            m /= fact;
        }

        if (fact_count) {
            factors.push_back(make_pair(fact, fact_count));
        }
    }

    if (m > 1) {
        factors.push_back(make_pair(m, 1));
    }
}

// Finds the inverse of a for any mod
int inverse(const int& a, const int& mod) {
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    int r1 = a;
    int r2 = mod;

    while (r2 != 0) {
        int q = r1 / r2;
        int ns = s1 - q * s2;
        int nt = t1 - q * t2;
        int nr = r1 % r2;
        s1 = s2;
        t1 = t2;
        r1 = r2;
        
        s2 = ns;
        t2 = nt;
        r2 = nr;
    }
    
    return (s1 + mod) % mod;
}
/*
 * Computes n^e mod m for a "large" e.
 *
 * Factorize m into many m_i = p_i^k_i
 * Then if p_i is not a factor of n,
 *
 * n^e mod m_i = n^(e mod phi(m_i)) mod m_i
 *
 * If p_i is a factor of n, then since e is considered "large",
 * n^e mod m_i = 0
 *
 * Now we combine the results using the chinese remainder theorem
 * If x = a_i (mod n_i)
 * Then x = sum_i a_i N / n_i inverse(N / n_i mod n_i)
 *
 * Therefore
 * n^e mod m = sum_i n^(e mod phi(m_i)) M_i N_i
 * Only taking the m_i where p_i does not divide n
 */
int exponial(int n, int m) {
    if (n <= 4) {
        return table[n] % m;
    }

    if (m <= 1) return 0;

    // printf("%d %d\n", n, m);

    vector<pair<int, int> > factors;
    factor(m, factors);

    int ans = 0;
    for (const pair<int, int>& factor : factors) {
        int prime = factor.first;
        int pow = factor.second;

        // printf("Factor of %d is %d^%d = %d\n", m, prime, pow, modpow(prime, pow, m + 1));

        if (n % prime == 0) continue;

        int m_i = modpow(prime, pow, m + 1);
        int M_i = m / m_i;
        int N_i = inverse(M_i, m_i);

        int phi_mi = m_i - (m_i / prime);
        // printf("m = %d, m_i = %d, phi_mi = %d\n", m, m_i, phi_mi);
        int chunk = prod(modpow(n, exponial(n - 1, phi_mi), m_i), prod(M_i, N_i, m), m);

        ans = sum(ans, chunk, m);
    }

    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d\n", exponial(n, m));

    return 0;
}
