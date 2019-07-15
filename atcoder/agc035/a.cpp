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

    // 0 0 0
    // 0 1 1
    // 1 1 0
    // 1 0 1
    //
    // if you start with a pair of hats, that fixes the rest of the sequence
    //
    // n = 3
    // a, b, a ^ b
    //
    // n = 4
    // a, b, a^b, a
    //
    // a ^ b == a
    // only poss if b = 0
    //
    // n = 5
    // a, b, a ^ b, a, 0
    //
    int n;
    cin >> n;
    vi a(n);

    bool all_zero = true;
    for (auto& x : a) {
        cin >> x;
        if (x > 0) {
            all_zero = false;
        }
    }

    if (all_zero) {
        cout << "Yes\n";
        return 0;
    }

    if (n % 3 != 0) {
        cout << "No\n";
        return 0;
    }

    // each bit has to have a repeated form: 
    // 000, 011, 101, 110
    // count # of bits for each?
    vi freq(30, 0);
    for (auto& x : a) {
        for (int j = 0; j < 30; ++j) {
            if (x & (1 << j)) {
                ++freq[j];
            }
        }
    }

    for (int j = 0; j < 30; ++j) {
        if (!freq[j]) continue;

        if (freq[j] % 2 != 0 or (freq[j] / 2) * 3 != n) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}
