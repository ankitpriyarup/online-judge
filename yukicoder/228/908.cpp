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
    getline(cin, s);

    int n = s.size();
    bool valid = true;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            valid &= ('a' <= s[i] and s[i] <= 'z');
        } else {
            valid &= s[i] == ' ';
        }
    }
    
    cout << (valid ? "Yes" : "No") << '\n';
    
    return 0;
}
