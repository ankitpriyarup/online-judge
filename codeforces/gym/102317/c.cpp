#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void fall_row(vector<vector<char>>& board, vector<char>& stable_row, vector<char>& stable_col, int i) {
    for (int j = 0; j < board[i].size(); ++j) {
        board[i][j] = false;
    }
}

void fall_col(vector<vector<char>>& board, vector<char>& stable_row, vector<char>& stable_col, int j) {
    for (int i = 0; i < board.size(); ++i) {
        board[i][j] = false;
    }
}

int solve() {
    int n, q;
    cin >> n >> q;

    vector<char> stable_row(n, 1);
    vector<char> stable_col(n, 1);

    int ans = 0;
    while (q-- > 0) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        if (stable_row[x] or stable_col[y]) {
            stable_row[x] = false;
            stable_col[y] = false;
        } else {
            ans++;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    int tc = 1;
    while (T-- > 0) {
        cout << "Strategy #" << tc++ << ": " << solve() << '\n' << '\n';
    }
    
    return 0;
}
