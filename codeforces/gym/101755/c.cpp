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
        cin >> a[i].second >> a[i].first;
    }
    sort(all(a));
    vi ans;
    for (auto& p : a) {
        int r, l;
        tie(r, l) = p;
        if (ans.empty() or ans.back() < l) {
            ans.push_back(r);
        }
    }

    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }

    
    return 0;
}
