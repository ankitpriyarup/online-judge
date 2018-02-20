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

constexpr int MOD = 1000000000;

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

void dfs(int n, int mask, int new_mask, int pos, matrix<mll>& res) {
    if (pos == n) {
        res(new_mask, mask) = res(new_mask, mask) + 1;
        return;
    }

    if (mask & (1 << pos)) {
        dfs(n, mask, new_mask ^ (1 << pos), pos + 1, res);
    } else {
        // if this is a 0, you need to fill it
        // fill with 1x1
        dfs(n, mask, new_mask, pos + 1, res);
        // fill with 1x2
        dfs(n, mask, new_mask ^ (1 << pos), pos + 1, res);
        // fill with 2x1
        if (pos + 1 < n and ((mask & (1 << (pos + 1))) == 0)) {
            dfs(n, mask, new_mask, pos + 2, res);
        }
    }
}

matrix<mll> build_mat(int n) {
    matrix<mll> res(1 << n);
    for (int mask = 0; mask < (1 << n); ++mask) {
        dfs(n, mask, mask, 0, res);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    ll m;
    scanf("%d %lld", &n, &m);

    matrix<mll> base = build_mat(n);
    matrix<mll> sq = base.pow(m);

    /*
    cout << base << '\n';
    cout << sq << '\n';
    */

    printf("%lld\n", sq(0, 0).val);

    return 0;
}
