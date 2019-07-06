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
    vi a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (a.empty() or x >= a.back()) {
            a.push_back(x);
        } else {
            *upper_bound(all(a), x) = x;
        }
    }

    cout << a.size() << '\n';

    return 0;
}
