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
        string s;
        cin >> s;

        int flip = 0;
        int ans = 0;
        while (!s.empty()) {
            if ((s.back() == 'a') == !flip) {
                ++ans;
                flip = !flip;
            }
            s.pop_back();
        }

        cout << ans << '\n';
    }
    
    return 0;
}
