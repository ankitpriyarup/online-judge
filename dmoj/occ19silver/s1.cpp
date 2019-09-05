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

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    ll res = abs(x2 - x1) * abs(y2 - y1) + abs(x4 - x3) * abs(y4 - y3);
    int x5 = max(min(x1, x2), min(x3, x4));
    int x6 = min(max(x1, x2), max(x3, x4));
    int y5 = max(min(y1, y2), min(y3, y4));
    int y6 = min(max(y1, y2), max(y3, y4));

    res -= 1LL * max(0, x6 - x5) * max(0, y6 - y5);

    cout << res << '\n';
    
    return 0;
}
