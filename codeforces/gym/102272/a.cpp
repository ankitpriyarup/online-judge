#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

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

    ll expo;
    cin >> expo;

    matrix<mll> trans(45);
    for (int i = 0; i + 1 < 45; ++i) {
        trans(i, i + 1) = mll(1);
    }

    trans(9, 0) = mll(16);
    trans(19, 0) = mll(9);
    trans(29, 0) = mll(4);
    trans(39, 0) = mll(1);

    auto res = trans.pow(expo);
    mll ans(0);

    for (int i = 0; i < 45; ++i) {
        ans = ans + res(0, i);
    }

    cout << ans.val << '\n';
    
    return 0;
}
