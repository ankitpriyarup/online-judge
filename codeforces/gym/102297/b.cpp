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
        vi usa(3), rus(3);
        int a = 0;
        int b = 0;
        for (auto& m : usa) {
            cin >> m;
            a += m;
        }

        for (auto& m : rus) {
            cin >> m;
            b += m;
        }

        bool count = a > b;
        bool color = usa > rus;

        for (int i = 0; i < 3; ++i) {
            if (i)
                cout << ' ';
            cout << usa[i];
        }
        for (int i = 0; i < 3; ++i) {
            cout << ' ' << rus[i];
        }
        cout << '\n';

        if (count and color) {
            cout << "both\n";
        } else if (count) {
            cout << "count\n";
        } else if (color) {
            cout << "color\n";
        } else {
            cout << "none\n";
        }
        cout << '\n';
    }
    
    return 0;
}
