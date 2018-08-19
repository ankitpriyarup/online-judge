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

template<typename T>
struct matrix {
    int N;
    vector<T> dat;

    explicit matrix<T>(int _N, T fill = T(0), T diag = T(0)) {
        N = _N;
        dat.resize(N * N, fill);

        for (int i = 0; i < N; i++)
            (*this)(i, i) = diag;
    }

    T& operator()(int i, int j) {
        return dat[N * i + j];
    }

    matrix<T> operator*(matrix<T> &b) {
        matrix<T> r(N);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    r(i, j) = r(i, j) + (*this)(i, k) * b(k, j);

        return r;
    }

    vector<T> operator*(vector<T> &v) {
        vector<T> r(N, T(0));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                r[i] = r[i] + (*this)(i, j) * v[j];
            }
        }

        return r;
    }

    matrix<T> pow(ll expo) {
        if(!expo) return matrix<T>(N, T(0), T(1));
        matrix<T> r = (*this * *this).pow(expo/2);
        return (expo&1) ? (r * *this) : r;
    }

    friend ostream& operator<<(ostream &os, matrix<T> &m) {
        os << "{";
        for (int i = 0; i < m.N; i++) {
            if(i) os << "},\n ";
            os << "{";
            for (int j = 0; j < m.N; j++) {
                if(j) os << ", ";
                os << setw(00) << m(i, j) << setw(0);
            }
        }
        return os << "}}";
    }
};

int MOD;

struct mll {
    int val;
    explicit mll(int _val = 0): val(_val) {
        val %= MOD;
        if (val < 0)
            val += MOD;
    }

    bool operator==(const mll& o) const {
        return val == o.val;
    }

    mll operator+(const mll& o) const {
        return mll(val + o.val);
    }

    mll operator*(const mll& o) const {
        return mll(1LL * val * o.val % MOD);
    }

    friend ostream& operator<<(ostream &os, mll &m) {
        return os << m.val;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    vector<int> coeffs(n + 1);
    for (int i = 0; i <= n; ++i) {
        scanf(" %d", &coeffs[i]);
    }

    vector<int> inits(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &inits[i]);
    }

    int q;
    scanf(" %d", &q);
    ll t;
    while (q-- > 0) {
        scanf(" %lld %d", &t, &MOD);
        matrix<mll> mat(n + 1);
        vector<mll> vec(n + 1);

        for (int i = 0; i < n - 1; ++i) {
            mat(i, i + 1) = mll(1);
            vec[i] = mll(inits[i]);
        }

        vec[n - 1] = mll(inits[n - 1]);
        vec[n] = mll(1);
        for (int i = 0; i <= n; ++i) {
            mat(n - 1, n - i) = mll(coeffs[i]);
        }

        mat(n, n) = mll(1);

        matrix<mll> big = mat.pow(t);

        vector<mll> res = big * vec;
        printf("%d\n", res[0].val);
    }

    return 0;
}
