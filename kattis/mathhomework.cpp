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

    int b, d, c, l;
    cin >> b >> d >> c >> l;

    bool found = false;
    for (int x = 0; x <= l; ++x) {
        for (int y = 0; y <= l; ++y) {
            for (int z = 0; z <= l; ++z) {
                int tot = b * x + d * y + c * z;
                if (tot == l) {
                    found = true;
                    cout << x << ' ' << y << ' ' << z << '\n';
                }
            }
        }
    }

    if (!found) {
        cout << "impossible\n";
    }
    
    return 0;
}
