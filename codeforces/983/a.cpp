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
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

ll modmul64(ll a, ll b, ll m) {
    if (a > b) {
        swap(a, b);
    }

    ll res = 0LL;
    ll cur = b % m;
    for (ll p = 1; p <= a; p <<= 1) {
        if (p & a) {
            res += cur;
            while (res >= m)
                res -= m;
        }
        
        cur <<= 1;
        while (cur >= m) {
            cur -= m;
        }
    }

    return res;
}

inline bool is_finite(ll q, ll b) {
    ll v = b % q;
    for (int i = 0; i <= 7; ++i) {
        if (v == 0) {
            return true;
        }

        v = modmul64(v, v, q);
    }

    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    ull p, q, b;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf(" %llu %llu %llu", &p, &q, &b);
        ll g = gcd(p, q);
        p /= g;
        q /= g;

        if (is_finite(q, b))
            printf("Finite\n");
        else
            printf("Infinite\n");
    }

    return 0;
}
