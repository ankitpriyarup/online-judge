#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

struct mat {
    int data[2][2];

    mat() {
        memset(data, 0, sizeof(data));
    }

    mat(int x) {
        memset(data, 0, sizeof(data));
        data[0][0] = data[1][1] = x;
    }

    mat operator*(const mat& other) const {
        mat res;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    res.data[i][j] += 1LL * data[i][k] * other.data[k][j] % MOD;
                    if (res.data[i][j] >= MOD) {
                        res.data[i][j] -= MOD;
                    }
                }
            }
        }

        return res;
    }

    mat expo(int k) {
        if (k == 0) return mat(1);
        if (k == 1) return *this;
        mat t = (*this) * (*this);
        mat half = t.expo(k / 2);
        if (k % 2 == 1) return half * (*this);
        return half;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    mat fib;
    fib.data[0][0] = 0;
    fib.data[0][1] = 1;
    fib.data[1][0] = 1;
    fib.data[1][1] = 1;

    mat res = fib.expo(n);

    cout << res.data[1][0];
    
    return 0;
}
