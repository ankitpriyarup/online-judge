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

    vector<string> board(5);
    for (auto& row : board) {
        cin >> row;
    }

    bool valid = true;
    vi dx = {1, -1, 1, -1, 2, -2, 2, -2};
    vi dy = {2, 2, -2, -2, 1, 1, -1, -1};
    int knights = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] != 'k') continue;
            ++knights;
            for (int d = 0; d < 8; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (0 <= nx and nx < 5 and 0 <= ny and ny < 5 and board[nx][ny] == 'k') {
                    valid = false;
                }
            }
        }
    }

    valid &= knights == 9;

    cout << (valid ? "valid" : "invalid") << '\n';
    
    return 0;
}
