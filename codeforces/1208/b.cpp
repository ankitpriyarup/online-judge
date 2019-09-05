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
    vi a(n);
    for (auto& x : a)
        cin >> x;

    for (int k = 0; k <= n; ++k) {
        map<int, int> m;
        for (int i = k; i < n; ++i) {
            m[a[i]] += 1;
        }

        bool poss = m.size() == n - k;
        for (int i = 0; i + k < n; ++i) {
            ++m[a[i]];
            if (--m[a[i + k]] == 0) {
                m.erase(a[i + k]);
            }

            poss |= m.size() == (n - k);
        }

        if (poss) {
            cout << k << '\n';
            return 0;
        }
    }

    return 0;
}
