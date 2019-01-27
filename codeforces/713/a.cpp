#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    char op;
    ll x;

    auto read = [](ll y) {
        int v = 0;
        int p = 1;
        while (y) {
            if (y & 1) {
                v |= p;
            }

            y /= 10;
            p <<= 1;
        }

        return v;
    };

    vi f(1 << 18, 0);
    while (q-- > 0) {
        cin >> op >> x;
        if (op == '+') {
            int v = read(x);
            ++f[v];
        } else if (op == '-') {
            int v = read(x);
            --f[v];
        } else {
            int v = 0;
            int p = 1;
            while (x) {
                if (x & 1) {
                    v |= p;
                }

                x /= 10LL;
                p <<= 1;
            }

            cout << f[v] << '\n';
        }
    }
    return 0;
}
