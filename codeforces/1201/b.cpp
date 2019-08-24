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
    ll tot = 0;
    for (auto& x : a) {
        cin >> x;
        tot += x;
    }

    sort(all(a));
    if (tot % 2 == 1 or a.back() > tot - a.back()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    
    return 0;
}
