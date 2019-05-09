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

    int n;
    cin >> n;
    // give x, eat floor(x / 2)
    // x + (x / 2) <= n
    // 3x / 2 <= n

    // 123456789
    // 122344566

    if (n % 3 == 0) {
        cout << 2 * (n / 3) << '\n';
    } else if (n % 3 == 1) {
        cout << ((2 * (n / 3)) + 1) << '\n';
    } else {
        cout << 2 * ((n + 1) / 3) << '\n';
    }

    return 0;
}
