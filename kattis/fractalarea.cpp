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
    cout << fixed << setprecision(15);

    double pi = 3.141592653589793238;

    while (T-- > 0) {
        int r, n;
        cin >> r >> n;
        if (n == 1) {
            double area = pi * r * r;
            cout << area << '\n';
            continue;
        }

        double ans = r * r + r * r;
        double cur = r * r;
        for (int i = 2; i < n; ++i) {
            cur *= 0.75;
            ans += cur;
        }

        cout << pi * ans << '\n';
    }
    
    return 0;
}
