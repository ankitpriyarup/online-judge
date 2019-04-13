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

    constexpr int MAXN = 200005;
    int n;
    cin >> n;
    vi freq(MAXN, 0);
    vi inc, dec;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++freq[x];
        if (freq[x] == 1) {
            inc.push_back(x);
        } else if (freq[x] == 2) {
            dec.push_back(x);
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    sort(all(inc));
    sort(all(dec));
    reverse(all(dec));
    cout << "YES\n";
    cout << inc.size() << '\n';
    for (int x : inc) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << dec.size() << '\n';
    for (int x : dec) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}
