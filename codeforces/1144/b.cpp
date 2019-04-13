#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

ll f(vector<vi> a) {
    ll res = 0LL;
    int k = 0;
    while (true) {
        if (a[k].empty()) break;
        res += a[k].back();
        a[k].pop_back();
        k ^= 1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vi> a(2);
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x & 1].push_back(x);
        ans += x;
    }
    sort(all(a[0]));
    sort(all(a[1]));

    ll res = f(a);
    swap(a[0], a[1]);
    res = max(res, f(a));
    cout << (ans - res) << '\n';
    
    return 0;
}
