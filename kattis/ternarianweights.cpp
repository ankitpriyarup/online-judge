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

    int T;
    cin >> T;
    while (T-- > 0) {
        int x;
        cin >> x;
        vi l, r;
        for (int w = 1; x > 0; w *= 3) {
            if (x % 3 == 1) {
                r.push_back(w);
                x -= 1;
            } else if (x % 3 == 2) {
                l.push_back(w);
                x += 1;
            }

            x /= 3;
        }

        reverse(all(l));
        reverse(all(r));

        cout << "left pan:";
        for (auto& v : l) {
            cout << ' ' << v;
        }
        cout << '\n';

        cout << "right pan:";
        for (auto& v : r) {
            cout << ' ' << v;
        }
        cout << '\n';
        cout << '\n';
    }
    
    return 0;
}
