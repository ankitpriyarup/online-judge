#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int lis(const vi& b) {
    int n = b.size();
    vi res = {b[0]};
    for (int i = 1; i < n; ++i) {
        if (b[i] > res.back()) {
            res.push_back(b[i]);
        } else {
            auto it = upper_bound(all(res), b[i]);
            *it = b[i];
        }
    }

    return res.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        vector<pii> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }

        sort(all(a));
        vi b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = a[i].second;
        }

        cout << (n - lis(b)) << '\n';
    }
    
    return 0;
}
