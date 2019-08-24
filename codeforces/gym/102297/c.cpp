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
    for (int tc = 1; tc <= T; ++tc) {
        int s;
        ll b;
        cin >> s >> b;
        cout << "Practice #" << tc << ": " << s << ' ' << b << '\n';

        int n;
        cin >> n;
        vi a(n);
        for (auto& x : a) {
            cin >> x;
            while (b <= x) {
                b *= 2;
            }

            b -= x;

            cout << x << ' ' << b << '\n';
        }

        cout << '\n';
    }
    
    return 0;
}
