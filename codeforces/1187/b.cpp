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
    string s;
    cin >> s;
    vector<vi> pos(26);
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
    }

    int q;
    cin >> q ;
    while (q-- >0) {
        string t;
        cin >> t;

        vi freq(26, 0);
        int ans = 0;
        for (int i = 0; i < t.size(); ++i) {
            ans = max(ans, pos[t[i] - 'a'][freq[t[i] - 'a']]);
            ++freq[t[i] - 'a'];
        }

        cout << (ans + 1) << '\n';
    }
    
    return 0;
}
