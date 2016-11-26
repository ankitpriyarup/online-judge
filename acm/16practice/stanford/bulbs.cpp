#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int m, n;
char grid[404][404];
bool col_flip[404];

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> m >> n;
        for (int i = 0; i < m; ++i) {
            cin >> grid[i];

            int start = 0;
            int end = n - 1;
            while (start < end) {
                char t = grid[i][start];
                grid[i][start] = grid[i][end];
                grid[i][end] = t;

                ++start;
                --end;
            }
        }

        memset(col_flip, 0, sizeof(col_flip));
        int count = 0;
        for (int i = 0; i < m; ++i) {
            bool row_flip = false;
            for (int j = 0; j < n; ++j) {
                if ((grid[i][j] == '0' and !(row_flip ^ col_flip[j]))
                 || (grid[i][j] == '1' and  (row_flip ^ col_flip[j]))) {
                    row_flip = !row_flip;
                    col_flip[j] = !col_flip[j];
                    count += 1;
                }
            }
        }

        cout << count << '\n';
    }
}
