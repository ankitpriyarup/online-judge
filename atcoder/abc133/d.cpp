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
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int v = a[0] - a[n - 1];
    for (int i = 1; i < n - 1; ++i) {
        v = a[i] - v;
    }

    vi b(n);
    b[n - 1] = v / 2;
    for (int i = n - 2; i >= 0; --i) {
        b[i] = a[i] - b[i + 1];
    }

    for (int i = 0; i < n; ++i) {
        cout << (2 * b[i]) << ' ';
    }

    // a0 = x0 + x1
    // a1 = x1 + x2
    // a2 = x2 + x0
    //
    // a0 - an-1 = x0 + x1 - xn-1 - x0
    // a0 - an-1 = x1 - xn-1
    //
    // a1 - (a0 - xn-1) = x2 + xn-1
    //
    // a2 - (a1 - (a0 - xn-1)) = x3 - xn-1
    // a3 - (...) = -x4 - xn-1
    
    return 0;
}
