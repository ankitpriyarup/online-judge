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

    int x, y, z;
    cin >> x >> y >> z;
    x /= 100;
    x /= 100;
    x *= (100 + z);
    x *= (100 - y);
    cout << x << '\n';
    
    return 0;
}
