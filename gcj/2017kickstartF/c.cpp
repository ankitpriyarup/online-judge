#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 202;
// constexpr int MAXP = 202;
constexpr ll INF = 1e18;

int n, m, p;
ll adj[MAXN][MAXN];
ll adjsum[MAXN];

// starting from node i, what is the exp time to catch j pokemon
// ld dp[MAXN][MAXP];

template <typename T>
struct matrix {
    int dim;
    vector<T> data;

    matrix(int dim, T fill, T diag): dim(dim) {
        data.resize(dim * dim, fill);
        for (int i = 0; i < dim; ++i) {
            data[dim * i + i] = diag;
        }
    }

    T& operator()(int i, int j) {
        return data[dim * i + j];
    }

    matrix<T> operator*(matrix<T>& other) {
        matrix<T> ret(dim, T(0), T(0));

        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                for (int k = 0; k < dim; ++k) {
                    ret(i, j) += (*this)(i, k) * other(k, j);
                }
            }
        }

        return ret;
    }

    matrix<T> power(ll exp) {
        auto res = matrix<T>(dim, T(0), T(1));
        auto cur = res * (*this);

        for (ll p = 1; p <= exp; p <<= 1LL) {
            if (exp & p) {
                res = res * cur;
            }

            cur = cur * cur;
        }

        return res;
    }

    vector<T> operator*(const vector<T>& vec) {
        vector<T> ret(dim, T(0));
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                ret[i] += (*this)(i, j) * vec[j];
            }
        }

        return ret;
    }
};

void read() {
    scanf("%d %d %d", &n, &m, &p);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adj[i][j] = INF;
        }

        adj[i][i] = 0LL;
    }

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        adj[u][v] = w;
        adj[v][u] = w;
    }
}

void floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        adjsum[i] = 0LL;
        for (int j = 0; j < n; ++j) {
            adjsum[i] += adj[i][j];
        }
    }
}

void solve(int case_num) {
    floyd();
    /*
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0.0L;
    }
    */

    // vector is n 0 followed by a 1
    vector<ld> v(n + 1, 0.0L);
    v[n] = 1.0L;

    matrix<ld> mat(n + 1, 1.0 / (n - 1.0L), 0.0);

    for (int i = 0; i < n; ++i) {
        mat(i, n) = ((ld) adjsum[i]) / (n - 1.0L);
    }
    for (int j = 0; j < n; ++j) {
        mat(n, j) = 0.0L;
    }
    mat(n, n) = 1.0;

    matrix<ld> res = mat.power(p);
    vector<ld> ret = res * v;

    /*
    ld dpsum = 0.0L;
    for (int j = 1; j <= p; ++j) {
        for (int i = 0; i < n; ++i) {
            ld& ret = dp[i][j];

            ret = adjsum[i] + dpsum - dp[i][j - 1];
            ret /= (n - 1.0L);
        }

        dpsum = 0.0L;
        for (int i = 0; i < n; ++i) {
            dpsum += dp[i][j];
        }
    }
    */

    printf("Case #%d: %.12Lf\n", case_num, ret[0]);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int case_num = 1; case_num <= T; ++case_num) {
        read();
        solve(case_num);
    }

    return 0;
}
