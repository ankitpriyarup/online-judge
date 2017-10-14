#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

template <typename T>
struct mat {
    int n;
    vector<T> data;

    mat(int n, T fill = T(0), T diag = T(0)): n(n) {
        data.resize(n * n, fill);
        for (int i = 0; i < n; ++i) {
            (*this)(i, i) = diag;
        }
    }

    T& operator()(int i, int j) {
        return data[n * i + j];
    }

    mat<T> operator*(mat<T>& other) {
        mat<T> res(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    res(i, j) = res(i, j) + (*this)(i, k) * other(k, j);
                }
            }
        }

        return res;
    }

    vector<T> operator*(vector<T>& v) {
        vector<T> res(n, T(0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i] += (*this)(i, j) * v[j];
            }
        }

        return res;
    }

    mat<T> pow(ll exp) {
        if (exp == 0) {
            return mat<T>(n, T(0), T(1));
        }

        mat<T> squared = (*this * *this).pow(exp / 2);

        return (exp & 1) ? (*this * squared) : squared;
    }
};

void solve() {
    int n, links, time;
    scanf("%d %d %d", &n, &links, &time);
    vector<ld> init(n, 0.0);

    vector<vector<int> > graph(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        scanf("%Lf", &init[i]);
    }

    mat<ld> m(n);
    int u, v;
    ld amt;
    for (int i = 0; i < links; ++i) {
        scanf("%d %d %Lf", &u, &v, &amt);
        m(v, u) = amt;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int j = 0; j < n; ++j) {
        ld col_sum = 0.0L;
        for (int i = 0; i < n; ++i) {
            col_sum += m(i, j);
        }

        m(j, j) = 1.0L - col_sum;
    }

    mat<ld> powd = m.pow(time);

    vector<ld> out = powd * init;

    ld ans = 1e18;
    for (int i = 0; i < n; ++i) {
        ld cur = out[i];
        for (int child : graph[i]) {
            cur += out[child];
        }

        ans = min(ans, cur);
    }

    printf("%.15Lf\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        solve();
    }
    
    return 0;
}
