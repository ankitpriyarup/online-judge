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

constexpr ll MOD = 1000000007LL;
constexpr int MAXK = 505;
constexpr int MAXV = 55;

template<typename T>
struct matrix {
    int N;
    vector<T> dat;

    matrix<T> (int _N, T fill = T(0), T diag = T(0)) {
        N = _N;
        dat.resize(N * N, fill);

        for (int i = 0; i < N; i++)
            (*this)(i, i) = diag;
    }

    T& operator()(int i, int j) {
        assert(0 <= i and i < N);
        assert(0 <= j and j < N);
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

struct mll {
    ll val;
    explicit mll(ll _val = 0) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    int n, k;
    while (T-- > 0) {
        scanf(" %d %d", &n, &k);

        assert(n >= 1 and k >= 1);

        matrix<mll> trans(50);
        for (int i = 0; i + 1 < 50; ++i) {
            trans(i, i + 1) = mll(1);
        }

        int x;
        while (k-- > 0) {
            scanf(" %d", &x);
            assert(1 <= x and x <= 50);
            trans(49, 50 - x) = trans(49, 50 - x) + mll(1);
        }

        matrix<mll> res = trans.pow(n);

        if (res(49, 49).val == 0)
            printf("IMPOSSIBLE\n");
        else
            printf("%lld\n", res(49, 49).val);
    }

    return 0;
}
