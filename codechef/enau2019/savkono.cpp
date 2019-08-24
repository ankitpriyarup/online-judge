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
        int n, z;
        cin >> n >> z;
        multiset<int> ms;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ms.insert(-x);
        }

        int ans = 0;
        while (!ms.empty() and z > 0) {
            auto it = begin(ms);
            int x = -(*it);
            ms.erase(it);
            z -= x;
            ++ans;

            if (x >= 2) {
                ms.insert(-(x / 2));
            }
        }

        if (z > 0) {
            cout << "Evacuate\n";
        } else {
            cout << ans << '\n';
        }
    }
    
    return 0;
}
