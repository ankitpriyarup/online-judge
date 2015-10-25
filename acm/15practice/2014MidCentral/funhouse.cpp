#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int W, L;
    char grid[25][25];
    int c = 1;

    while (cin >> W >> L) {
        if (W == 0 && L == 0) {
            break;
        }
        
        for (int i = 0; i < L; ++i) {
            cin >> grid[i];
        }
        
        int sx;
        int sy;
        int dx = 0;
        int dy = 0;
        // find the start of the grid.
        for (int i = 0; i < W; ++i) {
            if (grid[0][i] == '*') {
                sx = 0;
                sy = i;
                dx = 1;
                break;
            } else if (grid[L - 1][i] == '*') {
                sx = L - 1;
                sy = i;
                dx = -1;
                break;
            }
        }
        
        for (int i = 0; i < L; ++i) {
            if (grid[i][0] == '*') {
                sx = i;
                sy = 0;
                dy = 1;
                break;
            } else if (grid[i][W - 1] == '*') {
                sx = i;
                sy = W - 1;
                dy = -1;
                break;
            }
        }

        do {
            // move in a direction
			sx += dx;
			sy += dy;
			if (grid[sx][sy] == '/') {
                int temp = dx;
                dx = - dy;
                dy = - temp;
			} else if (grid[sx][sy] == '\\') {
                int temp = dx;
                dx = dy;
                dy = temp;
            }
        } while (grid[sx][sy] != 'x');

		grid[sx][sy] = '&';
        cout << "HOUSE " << c++ << '\n';
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < W; ++j) {
				cout << grid[i][j];
			}
			cout << '\n';
		}
    }
    return 0;
}
