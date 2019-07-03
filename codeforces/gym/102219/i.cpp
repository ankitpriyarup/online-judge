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

    char ans = 'w';
    vector<string> grid(3);
    for (int i = 0; i < 3; ++i) {
        cin >> grid[i];
        int n = grid[i].size();
        bool active = false;
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '=') {
                active = true;
            } else if (active and grid[i][j] != '.') {
                ans = grid[i][j];
                break;
            }
        }

        if (ans != 'w')
            break;
    }

    if (ans == 'w') {
        cout << "You shall pass!!!\n";
    } else {
        cout << ans << '\n';
    }

    return 0;
}
