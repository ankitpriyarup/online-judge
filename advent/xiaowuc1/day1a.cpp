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
constexpr int LOW = 0;
constexpr int DIGITS = 10 - LOW;

// Taken from 
template<typename T> struct matrix {
    int N;
    vector<T> dat;

    matrix<T> (int _N, T fill = T(0), T diag = T(0)) {
        N = _N;
        dat.resize(N * N, fill);

        for (int i = 0; i < N; i++)
            (*this)(i, i) = diag;
    }

    T& operator()(int i, int j) {
        return dat[N * i + j];
    }

    matrix<T> operator *(matrix<T> &b) {
        matrix<T> r(N);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    r(i, j) = r(i, j) + (*this)(i, k) * b(k, j);

        return r;
    }

    vector<T> operator *(vector<T> &v) {
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

struct mll {
    ll val;
    mll(ll _val = 0) {
        val = _val % MOD;
        if (val < 0) val += MOD;
    }

    bool operator==(const mll& other) const {
        return val == other.val;
    }

    mll operator+(const mll &o) {
        return mll((val + o.val) % MOD);
    }

    mll operator*(const mll &o) {
        return mll((val * o.val) % MOD);
    }

    friend ostream& operator<<(ostream &os, mll &m) {
        return os << m.val;
    }
};

int ind(int x, int y) {
    return 10 * x + y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    int k = n / 2;

    /**
     * a c
     * b d
     */
	matrix<mll> mat(100);
    for (int a = 0; a <= 9; ++a) {
        for (int b = 0; b <= 9; ++b) {
            if (a != 0 and a == b) continue;

            for (int c = 0; c <= 9; ++c) {
                for (int d = 0; d <= 9; ++d) {
                    if (c != 0 and c == d) continue;
                    if ((c != 0 and a == c) or (d != 0 and b == d)) continue;

                    mat(ind(a, b), ind(c, d)) = mll(1);
                }
            }
        }
    }

    matrix<mll> powed = mat.pow(k - 1);
    // fix first column
    mll ans = mll(0);
    for (int a = 0; a <= 9; ++a) {
        for (int b = 0; b <= 9; ++b) {
            if (a != 0 and a == b) continue;

            vector<mll> vec(100, mll(0));
            vec[ind(a, b)] = mll(1);

            vector<mll> res = powed * vec;
            
            for (int c = 0; c <= 9; ++c) {
                for (int d = 0; d <= 9; ++d) {
                    if (c != 0 and c == d) continue;
                    if ((b != 0 and b == c) or (a != 0 and a == d)) continue;

                    ans = ans + res[ind(c, d)];
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
