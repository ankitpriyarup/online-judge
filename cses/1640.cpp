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

    map<int, int> m;
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (m.count(x - v)) {
            cout << (m[x - v] + 1) << ' ' << (i + 1) << '\n';
            return 0;
        }

        m[v] = i;
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
