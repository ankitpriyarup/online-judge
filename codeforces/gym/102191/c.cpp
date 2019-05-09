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

    if (n < 5) {
        cout << -1 << '\n';
        return 0;
    }

    // a b c d e
    // a c e b d
    //
    // a b c d e f
    // a c e b f d
    //
    // a b c d e f g
    // a c e g b d f
    //
    // a b c d e f g h
    // a c e g b h f d
    vi b;
    for (int i = 0; i < n; i += 2) {
        b.push_back(a[i]);
    }
    for (int i = 1; i < n; i += 2) {
        b.push_back(a[i]);
    }

    if (n % 2 == 0) {
        int h = (n >> 1);
        reverse(begin(b) + h + 1, end(b));
    }

    for (int x : b) {
        cout << x << ' ';
    }

    return 0;
}
