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
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    while (a.size() > 1) {
        /*
        for (auto& p : a) {
            cout << "[" << p.first << ", " << p.second << "] ";
        }
        cout << '\n';
        */

        int k = a[0].first;
        rotate(begin(a), begin(a) + (k % a.size()), end(a));
        a.pop_back();
    }

    cout << a[0].second << '\n';

    return 0;
}
