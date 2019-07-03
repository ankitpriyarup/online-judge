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
        multiset<int> old;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            old.insert(x);
        }

        for (int i = 1; i < n; ++i) {
            multiset<int> ndp;
            for (int j = 0; j < m; ++j) {
                int x;
                cin >> x;
                auto it = old.find(x);
                if (it != end(old) and *it == x) {
                    ++ans;
                    old.erase(it);
                }
                ndp.insert(x);
            }

            swap(old, ndp);
        }

        cout << ans << '\n';
    }
    
    return 0;
}
