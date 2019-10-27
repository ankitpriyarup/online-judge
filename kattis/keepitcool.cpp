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

    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<pii> a(s);
    int avail = 0;
    for (int i = 0; i < s; ++i) {
        cin >> a[i].first;
        a[i].second = i;

        avail += a[i].first;
    }

    sort(all(a));
    vi ans(s, 0);
    for (int i = 0; n > 0 and i < s; ++i) {
        int place = min(n, d - a[i].first);
        ans[a[i].second] = place;
        n -= place;
        avail -= a[i].first;
    }

    if (avail < m) {
        cout << "impossible\n";
        return 0;
    }

    for (int x : ans) {
        cout << x << ' ';
    }

    return 0;
}
