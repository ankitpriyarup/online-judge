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

    int n, p;
    cin >> n >> p;
    vi a(n);
    int h = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i] = (s.size() == 8);
        h += a[i];
    }

    ll x = 0;
    for (int i = n - 1; i >= 0; --i) {
        x *= 2LL;
        if (a[i]) {
            ++x;
        }
    }

    cout << (x * p - 1LL * h * p / 2LL) << '\n';
    
    return 0;
}
