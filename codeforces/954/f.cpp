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

constexpr ll MOD = 1000000007;
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
        while (val < 0) val += MOD;
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

int n;
ll m;

using event = tuple<ll, int, int>;

void row_on(matrix<mll>& mat, int row) {
    for (int i = 0; i < 3; ++i)
        mat(row, i) = mll(1);
    mat(0, 2) = mll(0);
    mat(2, 0) = mll(0);
}

void row_off(matrix<mll>& mat, int row) {
    for (int i = 0; i < 3; ++i)
        mat(row, i) = mll(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %lld", &n, &m);
    vector<event> events;
    int a;
    ll l, r;
    for (int i = 0; i < n; ++i) {
        scanf(" %d %lld %lld", &a, &l, &r);
        --a;
        events.emplace_back(l, a, 1);
        events.emplace_back(r + 1, a, -1);
    }
    sort(begin(events), end(events));

    matrix<mll> ans(3, mll(0), mll(1));

    matrix<mll> trans(3, mll(0), mll(0));
    for (int i = 0; i < 3; ++i)
        row_on(trans, i);

    ll pos = 1;
    int scores[3];
    memset(scores, 0, sizeof(scores));
    ll row, delta;
    ll time;
    for (const auto& evt : events) {
        tie(time, row, delta) = evt;
        if (time > pos) {
            auto tp = trans.pow(time - pos);
            ans = ans * tp;
            pos = time;
        }
        scores[row] += delta;
        if (scores[row] == 0LL and delta == -1) {
            row_on(trans, row);
        } else if (scores[row] == 1LL and delta == 1) {
            row_off(trans, row);
        }
    }

    if (pos < m) {
        auto tp = trans.pow(m - pos);
        ans = ans * tp;
    }
    printf("%lld\n", ans(1, 1).val);

    return 0;
}
