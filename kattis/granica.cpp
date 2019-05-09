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

    int n;
    cin >> n;

    vi a(n);
    int g = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < i; ++j) {
            g = gcd(g, abs(a[i] - a[j]));
        }
    }

    vi ans = {g};
    for (int m = 2; m * m <= g; ++m) {
        if (g % m == 0) {
            ans.push_back(m);
            if (m * m != g) {
                ans.push_back(g / m);
            }
        }
    }
    sort(all(ans));
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}
