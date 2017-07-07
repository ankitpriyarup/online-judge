/*
USER: rednano1
PROG: theme
LANG: C++11
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <complex>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 5000;
int n;
int a[MAXN];

constexpr int NHASH = 2;
constexpr int MODS[] = {static_cast<int>(1e9 + 7), static_cast<int>(1e9 + 9)};
constexpr int BASE = 199;
constexpr int ZERO = 100;

int powers[NHASH][MAXN];

inline int sum(const int& a, const int& b, const int& mod) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }

    return c;
}

inline int prod(const int& a, const int& b, const int& mod) {
    return (1LL * a * b) % mod;
}

struct my_hash {
    int size;
    int vals[NHASH];

    my_hash (int size): size(size) {
        for (int i = 0; i < NHASH; ++i) {
            vals[i] = 0;
        }
    }

    void update(int rem, int val) {
        for (int i = 0; i < NHASH; ++i) {
            vals[i] = prod(vals[i], BASE, MODS[i]);

            vals[i] = sum(vals[i],
                          MODS[i] - prod(rem + ZERO, powers[i][size], MODS[i]),
                          MODS[i]);

            vals[i] = sum(vals[i], val + ZERO, MODS[i]);
        }
    }

    bool operator==(const my_hash& other) const {
        for (int i = 0; i < NHASH; ++i) {
            if (vals[i] != other.vals[i])
                return false;
        }

        return true;
    }

    bool operator<(const my_hash& other) const {
        for (int i = 0; i < NHASH; ++i) {
            if (vals[i] < other.vals[i]) 
                return true;
            else if (vals[i] > other.vals[i])
                return false;
        }

        return false;
    }
};

void gen_powers(int n) {
    for (int i = 0; i < NHASH; ++i) {
        powers[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            powers[i][j] = (1LL * powers[i][j - 1] * BASE) % MODS[i];
        }
    }
}

map<my_hash, int> first_ind;

bool has_sol(int size) {
    bool DEBUG = false;

    first_ind.clear();
    --size;

    my_hash h(size);
    for (int i = 0; i < size; ++i) {
        h.update(-ZERO, a[i]);
    }

    if (DEBUG) {
        printf("%d %d\n", size - 1, h.vals[0]);
    }

    first_ind[h] = size - 1;
    for (int i = size; i < n; ++i) {
        h.update(a[i - size], a[i]);
        if (DEBUG) {
            printf("%d %d\n", i, h.vals[0]);
        }

        if (first_ind.find(h) != first_ind.end()) {
            int old_ind = first_ind[h];

            if (old_ind + size < i) {
                return true;
            }

        } else {
            first_ind[h] = i;
        }
    }

    return false;
}

int main() {
    freopen("theme.in", "r", stdin);
    freopen("theme.out", "w", stdout);

    scanf("%d", &n);
    gen_powers(n);
    --n;

    int x;
    scanf("%d", &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        int t = a[i];
        a[i] -= x;
        x = t;
    }

    if (!has_sol(5)) {
        printf("%d\n", 0);
        return 0;
    } else {
        int lo = 5;
        int hi = n;

        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (has_sol(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        printf("%d\n", lo);
    }

    return 0;
}
