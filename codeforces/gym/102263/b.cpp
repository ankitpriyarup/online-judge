#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int solve(int n, int k) {
    if (n == 0) {
        return 0;
    }

    set<int> s;
    for (int x = 1; x <= max(1, n - k); ++x) {
        s.insert(solve(n - x, k));
    }

    int v = 0;
    while (s.count(v))
        ++v;

    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    /*
    for (int j = 1; j <= 5; ++j) {
        for (int i = 0; i <= 10; ++i) {
            cout << i << ' ' << j << ' ' << solve(i, j) << '\n';
        }
    }

    for (int n = 1; n <= 10; ++n) {
        for (int k = 1; k <= 10; ++k) {
            int zeros = 1 + (k + 1) / 2;
            bool win = !(n < 2 * zeros and n % 2 == 0);
            cout << n << ' ' << k << ' ' << zeros << ' ' << solve(n, k) << '\n';
            assert(win == solve(n, k) > 0);
        }
    }
    */

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, k;
        cin >> n >> k;

        // 123456789
        // 22334455

        int zeros = 1 + (k + 1) / 2;
        if (n < 2 * zeros and n % 2 == 0) {
            cout << "Ayoub\n";
        } else {
            cout << "Kilani\n";
        }
    }
    
    return 0;
}
