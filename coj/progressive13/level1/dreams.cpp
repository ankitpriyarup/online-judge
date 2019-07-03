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
        int n, m;
        cin >> n >> m;
        vi used(n, false);
        while (m-- > 0) {
            int x;
            cin >> x;
            --x;
            used[x] = true;
        }

        bool first = true;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }
            if (!first)
                cout << ' ';
            cout << (i + 1);
            first = false;
        }
        cout << '\n';
    }
    
    return 0;
}
