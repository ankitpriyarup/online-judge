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

constexpr int MOD = 1e9 + 7;

struct mat {
    vector<int> data;

    mat(int diag = 0) {
        data.resize(16, 0);
        for (int i = 0; i < 4; ++i) {
            (*this)(i, i) = diag;
        }
    }

    inline int& operator()(int i, int j) {
        return data[4 * i + j];
    }

    mat operator*(mat& b) {
        mat res;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    res(i, j) = res(i, j) + (1LL * (*this)(i, k) * b(k, j)) % MOD;
                    if (res(i, j) >= MOD)
                        res(i, j) = res(i, j) - MOD;
                }
            }
        }

        return res;
    }

    mat pow(ll expo) {
        if (expo == 0) {
            return mat(1);
        } else {
            mat aa = ((*this) * (*this)).pow(expo / 2LL);
            return (expo & 1) ? (*this) * aa : aa;
        }
    }

    void print_mat() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                printf("%04d ", (*this)(i, j));
            }
            printf("\n");
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<mat> trans(16);
    for (int mask = 0; mask < 16; ++mask) {
        for (int i = 0; i < 4; ++i) {
            for (int j = i - 1; j <= i + 1; ++j) {
                if (j < 0 or j >= 4 or (mask & (1 << j)) > 0)
                    continue;

                trans[mask](j, i) += 1;
            }
        }
    }

    ll k;
    int n;
    scanf(" %lld %d", &k, &n);

    int lane;
    ll unit;
    vector<pair<ll, int>> cows;
    for (int i = 0; i < n; ++i) {
        scanf(" %d %lld", &lane, &unit);
        --lane;
        cows.emplace_back(unit, lane);
    }

    sort(begin(cows), end(cows));

    mat res(1);
    ll pos = 1;
    for (size_t i = 0; i < cows.size(); ++i) {
        ll dist = cows[i].first - pos;
        assert (dist > 0);
        res = trans[0].pow(dist - 1) * res;

        int mask = (1 << cows[i].second);
        while (i < cows.size() and cows[i + 1].first == cows[i].first) {
            ++i;
            mask |= (1 << cows[i].second);
        }

        res = trans[mask] * res;
        pos = cows[i].first;
    }

    res = trans[0].pow(k - pos) * res;
    printf("%d\n", res(0, 0));

    return 0;
}
