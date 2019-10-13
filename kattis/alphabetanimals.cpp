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
    int n;
    cin >> n;
    vector<string> names(n);
    vector<vi> letters(26);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        letters[names[i][0] - 'a'].push_back(i);
    }
    
    vi options = letters[s.back() - 'a'];
    if (options.empty()) {
        cout << "?\n";
        return 0;
    } else {
        int ans = -1;
        for (int x : options) {
            int idx = names[x].back() - 'a';
            if (letters[idx].empty() or letters[idx] == vi{x}) {
                ans = x;
                break;
            }
        }

        if (ans >= 0) {
            cout << names[ans] << "!\n";
        } else {
            cout << names[options[0]] << '\n';
        }
    }
}
