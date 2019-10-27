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

    string t;
    if (s.size() % 2 == 1) {
        t = s.substr(0, 3);
        s = s.substr(3);
    }

    while (!s.empty()) {
        if (!t.empty()) {
            t += '-';
        }
        t += s.substr(0, 2);
        s = s.substr(2);
    }

    cout << t << '\n';
    
    return 0;
}
