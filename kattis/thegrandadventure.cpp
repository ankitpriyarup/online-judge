#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

string pairs[] = {"$b", "|t", "*j"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        string s;
        cin >> s;

        bool valid = true;
        vector<char> stk;
        for (char c : s) {
            if (!valid) break;
            for (int i = 0; valid and i < 3; ++i) {
                if (c == pairs[i][0]) {
                    stk.push_back(c);
                    break;
                } else if (c == pairs[i][1]) {
                    if (stk.empty() or stk.back() != pairs[i][0]) {
                        valid = false;
                    } else {
                        stk.pop_back();
                    }
                    break;
                }
            }
        }

        valid &= stk.empty();
        cout << (valid ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
