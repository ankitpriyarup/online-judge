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
    vi b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    bool valid = a[0] == b[0];
    vi c, d;

    for (int i = 1; i < n; ++i) {
        c.push_back(a[i] - a[i - 1]);
        d.push_back(b[i] - b[i - 1]);
    }
    sort(all(c));
    sort(all(d));
    valid &= (c == d);

    cout << (valid ? "Yes" : "No") << '\n';
    return 0;
}
