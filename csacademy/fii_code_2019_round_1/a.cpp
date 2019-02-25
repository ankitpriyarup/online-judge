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

    ll a, b, m;
    cin >> a >> b >> m;
    if (a / m == b / m) {
        cout << (b % m) << '\n';
    } else {
        cout << (m - 1) << '\n';
    }
    
    return 0;
}
