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

    int a, x, y;
    cin >> a >> x >> y;
    // square goes from (-a, a)
    x <<= 1;
    y <<= 1;
    if (y % (2 * a) == 0) {
        cout << -1 << '\n';
        return 0;
    }

    if (y < 2 * a) {
        if (-a < x and x < a) {
            cout << 1 << '\n';
            return 0;
        } else {
            cout << -1 << '\n';
            return 0;
        }
    }
    y -= 2 * a;
    int base = y / 4 / a;
    y %= 4 * a;
    if (y < 2 * a) {
        if (-a < x and x < a) {
            cout << (2 + 3 * base) << '\n';
            return 0;
        }
    } else {
        if (-2 * a < x and x < 0) {
            cout << (3 + 3 * base) << '\n';
            return 0;
        } else if (0 < x and x < 2 * a) {
            cout << (4 + 3 * base) << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
