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

    int x, y, h, v, t;
    cin >> x >> y >> h >> v >> t;
    for (int i = 0; i < t; ++i) {
        int px = i;
        int py = 2 * i;

        int k = max((x - px + 1) / 2, (y - py));
        int nx = px + 2 * k;
        int ny = py + k;
        if (i + k < t and x <= nx and nx <= x + h and y <= ny and ny <= y + v) {
            // cout << i << ' ' << k << '\n';
            cout << "YES\n";
            return 0;
        }
    }
    
    cout << "NO\n";
    return 0;
}
