#include <cstdio>
#include <cstring>

using namespace std;

int grid[4][4];
int temp[4][4];

void rotate() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[3 - j][i] = grid[i][j];
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            grid[i][j] = temp[i][j];
        }
    }
}

void shift_row(int row) {
    memset(temp, 0, sizeof(temp));
    int target = 0;
    for (int j = 0; j < 4; ++j) {
        if (grid[row][j] == 0) continue;

        if (temp[row][target] == 0) {
            temp[row][target] = grid[row][j];
        } else if (temp[row][target] == grid[row][j]) {
            temp[row][target] *= 2;
            ++target;
        } else {
            ++target;
            temp[row][target] = grid[row][j];
        }
    }

    for (int j = 0; j < 4; ++j) {
        grid[row][j] = temp[row][j];
    }
}

void shift_left() {
    for (int i = 0; i < 4; ++i) {
        shift_row(i);
    }
}

int main() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    int move;
    scanf("%d", &move);

    for (int x = 0; x < move; ++x) {
        rotate();
    }

    shift_left();

    for (int x = 0; x < 4 - move; ++x) {
        rotate();
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%d%c", grid[i][j], j == 3 ? '\n' : ' ');
        }
    }

    return 0;
}
