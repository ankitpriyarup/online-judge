#include <iostream>

using namespace std;

int prod(int a, int b, int mod) {
    return (1LL * a * b) % mod;
}

int modpow(int base, int exp, int mod) {
    int cur = base;
    int p = 1;
    int ret = 1;

    while (p <= exp) {
        if (p & exp) {
            ret = prod(ret, cur, mod);
        }

        cur = prod(cur, cur, mod);
        p <<= 1;
    }

    return ret;
}

bool prime(int x) {
    if (x < 2) {
        return false;
    }

    if (x == 2) {
        return true;
    }

    if (x % 2 == 0) {
        return false;
    }

    for (int i = 3; 1LL * i * i <= 1LL * x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int p, a;
    while (cin >> p >> a) {
        if (p == 0 and a == 0) {
            break;
        }

        if (!prime(p) and modpow(a, p, p) == a) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
