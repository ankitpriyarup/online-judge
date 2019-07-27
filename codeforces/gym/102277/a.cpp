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

    int w, h, d;
    cin >> w >> h >> d;
    w -= min(w, 2 * d);
    h -= min(h, 2 * d);

    cout << max(0, w * h) << '\n';
    
    return 0;
}
