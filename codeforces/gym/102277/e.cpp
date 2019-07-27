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

    map<string, int> names;
    map<char, int> letters;
    while (n-- > 0) {
        string name;
        cin >> name;
        names[name] += 1;
        letters[name[0]] += 1;
    }

    ll ans = 0LL;
    for (auto& p : letters) {
        ll opts = p.second;
        ans += opts * (opts - 1);
    }

    for (auto& p : names) {
        ll opts = p.second;
        ans -= opts * (opts - 1);
    }

    cout << ans << '\n';
    
    return 0;
}
