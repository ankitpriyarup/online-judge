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

    int ans = 0;
    int n = 5;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "P")
            ++ans;
    }

    cout << ans << '\n';
    
    return 0;
}
