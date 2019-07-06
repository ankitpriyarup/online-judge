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
    vi lis;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (lis.empty() or x > lis.back()) {
            lis.push_back(x);
        } else {
            auto it = lower_bound(all(lis), x);
            *it = x;
        }
    }

    cout << lis.size() << '\n';

    return 0;
}
