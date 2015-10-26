#include <iostream>
#include <cstring>

using namespace std;

string convert(int row, char col) {
    char c = col + 'A';
    string ans = "";
    ans += c;
    ans += " ";
    ans += to_string(row + 1);
    return ans;
}

int main() {
    int T;
    cin >> T;
    int board[8][8];
    while (T-- > 0) {
        int r1, r2;
        char c1, c2;
        cin >> c1 >> r1 >> c2 >> r2;
        c1 -= 'A';
        c2 -= 'A';
        r1--;
        r2--;

        memset(board, 0, sizeof(board));

        if ((r1 + c1) % 2 != (r2 + c2) % 2) {
            cout << "Impossible\n";
        } else if (r1 == r2 && c1 == c2) {
            cout << 0 << " " << ((char)(c1 + 'A')) << ' ' << (r1 + 1) << '\n';
        } else {
            int dx[] = {1, -1, 1, -1};
            int dy[] = {1, 1, -1, -1};
            int r3;
            char c3;
            int ans = -1;
            for (int d = 0; ans < 0 && d < 4; ++d) {
                int nx = r1 + dx[d];
                int ny = c1 + dy[d];
                while (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
                    if (nx == r2 && ny == c2) {
                        ans = 1;
                        break;
                    }
                    board[nx][ny] = 1;
                    nx += dx[d];
                    ny += dy[d];
                }
            }

            for (int d = 0; ans < 0 && d < 4; ++d) {
                int nx = r2 + dx[d];
                int ny = c2 + dy[d];
                while (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
                    if (board[nx][ny] == 1) {
                        ans = 2;
                        r3 = nx;
                        c3 = ny;
                        break;
                    }
                    nx += dx[d];
                    ny += dy[d];
                }
            }

            if (ans == 1) {
                cout << "1 " << convert(r1, c1) << " " << convert(r2, c2) << '\n';
            } else {
                cout << "2 " << convert(r1, c1) << " " << convert(r3, c3) << " " << convert(r2, c2) << '\n';
            }
        }
    }
    return 0;
}
