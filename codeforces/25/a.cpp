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

    int n;
    cin >> n;
    vector<vector<pii>> a(2);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x % 2].emplace_back(x, i);
    }

    if (a[0].size() == 1) {
        cout << a[0][0].second + 1;
    } else {
        cout << a[1][0].second + 1;
    }
    
    return 0;
}
