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

    char owner;
    cin >> owner;
    vector<int> had(26, false);
    had[owner - 'A'] = true;

    int ans = 1;

    int n;
    cin >> n;

    while (n-- > 0) {
        char x, y;
        cin >> x >> y;
        if (owner == y) {
            owner = x;
            if (!had[owner - 'A']) {
                ++ans;
                had[owner - 'A'] = true;
            }
        }
    }

    cout << owner << '\n' << ans << '\n';
    
    return 0;
}
