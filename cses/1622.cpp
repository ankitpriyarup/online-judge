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

    string s;
    cin >> s;
    sort(all(s));

    vector<string> ans;
    do {
        ans.push_back(s);
    } while(next_permutation(all(s)));

    cout << ans.size() << '\n';
    for (const auto& t : ans) {
        cout << t << '\n';
    }

    return 0;
}
