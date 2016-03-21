#include <iostream>
#include <cstring>

using namespace std;

int grid[101][101];
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a * b < n) {
        cout << -1 << '\n';
        return 0;
    }

    memset(grid, 0, sizeof(grid));

    int x = 1;
    for (int i = 0; i < a; ++i) {
        if (x > n) break;
        if (i > 0 and grid[i - 1][0] % 2 == x % 2) {
            for (int j = b - 1; j >= 0; --j) {
                if (x > n) break;
                grid[i][j] = x++;
            }
        } else {
            for (int j = 0; j < b; ++j) {
                if (x > n) break;
                grid[i][j] = x++;
            }
        }
    }

    for (int i = 0; i < a; ++i) {
        cout << grid[i][0];
        for (int j = 1; j < b; ++j) {
            cout << ' ' << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}
