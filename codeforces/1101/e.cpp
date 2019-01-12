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

    int q;
    cin >> q;

    char op;
    int max_x = 0;
    int max_y = 0;
    while (q-- > 0) {
        cin >> op;
        if (op == '+') {
            int x, y;
            cin >> x >> y;
            if (x > y) {
                swap(x, y);
            }

            max_x = max(max_x, x);
            max_y = max(max_y, y);
        } else {
            int w, h;
            cin >> w >> h;
            if (w > h) {
                swap(w, h);
            }

            bool valid = max_x <= w and max_y <= h;
            cout << (valid ? "YES" : "NO") << '\n';
        }
    }

    
    return 0;
}
