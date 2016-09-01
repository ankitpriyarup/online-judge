#include <iostream>
#include <cstring>

using namespace std;

int n;
long long grid[3003][3003];

long long ldiag[3003]; // x + y
long long rdiag[6006]; // x - y

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // assume grid is filled with numbers.
    memset(ldiag, 0, sizeof(ldiag));
    memset(rdiag, 0, sizeof(rdiag));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ldiag[i + j] += grid[i][j];
            rdiag[i - j + 3000] += grid[i][j];
        }
    }

    long long even = -1LL;
    long long odd = -1LL;
    long long score;
    int x1, x2, y1, y2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) & 1) {
                score = ldiag[i + j] + rdiag[i - j + 3000] - grid[i][j];
                if (score > odd) {
                    odd = score;
                    x1 = i + 1;
                    y1 = j + 1;
                }
            } else {
                score = ldiag[i + j] + rdiag[i - j + 3000] - grid[i][j];
                if (score > even) {
                    even = score;
                    x2 = i + 1;
                    y2 = j + 1;
                }
            }
        }
    }

    cout << (even + odd) << '\n';
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    return 0;
}
