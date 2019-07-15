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

    int n, m;
    cin >> n >> m;

    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }

    vector<pair<int, ll>> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
    }
    sort(all(b));
    for (int i = 1; i < m; ++i) {
        b[i].second += b[i - 1].second;
    }

    for (auto& x : a) {
        if (x < b[0].first) {
            cout << 0 << ' ';
        } else {
            int lo = 0;
            int hi = m;
            while (lo + 1 < hi) {
                int mid = (lo + hi) >> 1;
                if (b[mid].first <= x){ 
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            cout << b[lo].second << ' ';
        }
    }
    
    return 0;
}
