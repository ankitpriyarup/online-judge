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
        bool mack = false;
        bool zack = false;
        vi a(10);
        for (auto& x : a) {
            cin >> x;
            if (x == 18)
                mack = true;
            else if (x == 17)
                zack = true;
        }

        for (int i = 0; i < 10; ++i) {
            if (i)
                cout << ' ';
            cout << a[i];
        }
        cout << '\n';
        if (mack and zack) {
            cout << "both\n";
        } else if (mack) {
            cout << "mack\n";
        } else if (zack) {
            cout << "zack\n";
        } else {
            cout << "none\n";
        }
        cout << '\n';
    }
    
    return 0;
}
