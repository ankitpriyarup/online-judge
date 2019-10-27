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
    vector<pii> a;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        a.emplace_back(x, i + 1);
    }

    sort(all(a));
    cout << 1;
    for (auto& p : a) {
        cout << ' ' << p.second;
    }
    
    return 0;
}
