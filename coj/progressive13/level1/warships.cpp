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

    string s, t;
    int x, y;
    while (cin >> s >> x >> t >> y) {
        int winner = 0;
        if (s[0] == t[0]) {
            if (x > y) winner = 1;
            else if (x < y) winner = -1;
        } else if ((s[0] == 'B' and t[0] == 'D') or 
                (s[0] == 'D' and t[0] == 'C') or 
                (s[0] == 'C' and t[0] == 'B')) {
            if (y >= 2 * x) winner = -1;
            else winner = 1;
        } else {
            if (x >= 2 * y) winner = 1;
            else winner = -1;
        }

        if (winner == 1) {
            cout << "Tobby\n";
        } else if (winner == -1) {
            cout << "Naebbirac\n";
        } else {
            cout << "Draw\n";
        }
    }

    return 0;
}
