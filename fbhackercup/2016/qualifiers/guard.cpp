#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int N;
char grid[2][1003];

/*
.X...X..
...X...X

ANSWER: 4


.....X.....
XXXX.X.XXXX

ANSWER: 2

...X
X.X.

ANSWER: 2

................
................

ANSWER: 2

.XXXX.....X
XX...XXXX.X

ANSWER: 3

...X...X..
.X...X...X

ANSWER: 5

.X.X.X.X.X.X
X.X.X.X.X.X.

ANSWER: 12
*/

/*
 * Find the degree of every empty space. Place a guard at every point with
 * degree 0. For every node of degree 1 where the empty cell it is adjacent to
 * is in the same column, put a guard in the opposite row of the same column.
 *
 * After that, count the number of horizontal bands of continuous '.'s and add
 * that many guards to get a final answer.
 */

bool add_guard() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 'X') continue;

            if ((j == 0 or grid[i][j - 1] == 'X') and (j == N - 1 or grid[i][j + 1] == 'X')) {
                if (grid[1 - i][j] == 'X') {
                    grid[i][j] = 'X';
                } else {
                    int other = 1 - i;
                    grid[i][j] = 'X';
                    grid[other][j] = 'X';
                    for (int k = j - 1; k >= 0 and grid[other][k] == '.'; --k) {
                        grid[other][k] = 'X';
                    }

                    for (int k = j + 1; k < N and grid[other][k] == '.'; ++k) {
                        grid[other][k] = 'X';
                    }
                }
                
                return true;
            }
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        cin >> N;
        cin >> grid[0] >> grid[1];

        // fill up isolated spots
        int ans = 0;
        while (add_guard()) {
            ans++;
        }

        /*
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
        */

        for (int i = 0; i < 2; ++i) {
            char last = 'X';
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != last and last == '.') {
                    ans++;
                }

                last = grid[i][j];
            }

            if (last == '.') ans++;
        }

        cout << "Case #" << case_num << ": " << ans << '\n';
    }

    return 0;
}
