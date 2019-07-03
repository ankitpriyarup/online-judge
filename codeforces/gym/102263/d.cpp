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

    int n, m;
    cin >> n >> m;
    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }

    int g = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        g = __gcd(x, g);
    }

    for (auto& x : a) {
        x %= g;
    }
    sort(all(a));
    if (a[0] == a.back()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return 0;
}
