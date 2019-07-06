#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

char board[8][8];
int pos[8];
int ans;

void dfs(int row) {
    if (row == 8) {
        ++ans;
        return;
    }

    for (pos[row] = 0; pos[row] < 8; ++pos[row]) {
        if (board[row][pos[row]] == '*') {
            continue;
        }

        bool valid = true;
        for (int i = 0; i < row; ++i) {
            if (pos[i] == pos[row] or (i + pos[i] == row + pos[row]) or (i - pos[i] == row - pos[row])) {
                valid = false;
                break;
            }
        }

        if (valid)
            dfs(row + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> board[i][j];
        }
    }

    ans = 0;
    dfs(0);

    cout << ans << '\n';

    return 0;
}
