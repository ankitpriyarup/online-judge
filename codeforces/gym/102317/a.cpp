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
        vi a(3);
        for (auto& x : a)
            cin >> x;

        cout << a[0] << " " << a[1] << " " << a[2] << '\n';
        sort(all(a));
        if (a[2] < 10) {
            cout << "zilch\n";
        } else if (a[1] < 10) {
            cout << "double\n";
        } else if (a[0] < 10) {
            cout << "double-double\n";
        } else {
            cout << "triple-double\n";
        }

        cout << '\n';
    }
    
    return 0;
}
