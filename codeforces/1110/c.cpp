#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    /*
    vi cache(26, 0);
    for (int i = 0; i < 26; ++i) {
        int v = (1 << i) - 1;
        for (int u = 1; u < v; ++u) {
            cache[i] = max(cache[i], gcd(u ^ v, u & v));
        }
    }

    for (int i = 0; i < 26; ++i) {
        cout << cache[i] << ", ";
    }
    cout << '\n';
    */
    vi cache = {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

    while (q-- > 0) {
        int x;
        cin >> x;
        int y = (x + 1);
        if ((y & (y - 1)) == 0) {
            int p = 1;
            int j = 0;
            while ((p << 1) <= y) {
                ++j;
                p <<= 1;
            }
            cout << cache[j] << '\n';
        } else {
            int p = 1;
            while ((p << 1) <= x) {
                p <<= 1;
            }

            cout << ((p << 1) - 1) << '\n';
        }
    }
    
    return 0;
}
