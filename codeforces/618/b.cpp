#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int a[55][55];
int out[55];
bool used[55];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    memset(used, 0, sizeof(used));
    for (int i = 0; i < N; ++i) {
        // figure out which row has to be i
        int theRow = -1;
        for (int row = 0; row < N; ++row) {
            if (used[row]) continue;
            theRow = row;
            int maxInRow = -1;
            for (int col = 0; col < N; ++col) {
                maxInRow = max(maxInRow, a[row][col]);
            }

            if (maxInRow == i) {
                theRow = row;
                break;
            }
        }

        //cout << i << " " << theRow << '\n';
        //if (theRow < 0) cout << "PANIC\n";
        used[theRow] = 1;

        out[theRow] = i + 1;
    }

    cout << out[0];
    for (int i = 1; i < N; ++i) {
        cout << " " << out[i];
    }
    cout << '\n';

    return 0;
}
