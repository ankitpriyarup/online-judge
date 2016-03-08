//Problem        : Ultra Low-Def
//Language       : C++11
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 

using namespace std;

int M, N, S;
int matrix[17 * 17][17 * 17];
int inverse[17 * 17][17 * 17];
int input[17 * 17];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool pseudoinverse = false;

int convert(int x, int y) {
    return N * x + y;
}

void swap_row(int r1, int r2) {
    for (int c = 0; c < S; ++c) {
        int t = matrix[r1][c];
        matrix[r1][c] = matrix[r2][c];
        matrix[r2][c] = t;

        int t2 = inverse[r1][c];
        inverse[r1][c] = inverse[r2][c];
        inverse[r2][c] = t2;
    }
}

void add(int r1, int r2) {
    for (int c = 0; c < S; ++c) {
        matrix[r2][c] ^= matrix[r1][c];
        inverse[r2][c] ^= inverse[r1][c];
    }
}

void invert() {
    for (int row = 0; row < S; ++row) {
        // find the pivot row.
        if (matrix[row][row] == 0) {
            for (int r = row + 1; r < S; ++r) {
                if (matrix[r][row] == 1) {
                    swap_row(r, row);
                }
            }
        }

        if (matrix[row][row] == 0) {
            pseudoinverse = true;
            return;
        }

        // set every other row to 0 in this column
        for (int r = 0; r < S; ++r) {
            if (r == row) continue;
            if (matrix[r][row]) {
                add(row, r);
            }
        }
    }
}

int main() {
    cin >> M >> N;
    S = M * N;
    char c;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> c;
            input[convert(i, j)] = (c - '0');
        }
    }

    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int ij = convert(i, j);
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (!(ni < 0 || nj < 0 || ni >= M || nj >= M)) {
                    matrix[ij][convert(ni, nj)] = 1;
                    matrix[convert(ni, nj)][ij] = 1;
                }
            }
        }
    }

    memset(inverse, 0, sizeof(inverse));
    for (int i = 0; i < S; ++i) {
        inverse[i][i] = 1;
    }

    cout << "matrix" << '\n';
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    invert();

    cout << "matrix" << '\n';
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "inverse" << '\n';
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            cout << inverse[i][j] << ' ';
        }
        cout << '\n';
    }


    // assume you have a pseudoinverse. Find the dimension of the pseudo inverse
    int rank = S;
    for (int i = 0; i < S; ++i) {
        int s = 0;
        for (int j = 0; j < S; ++j) {
            s += inverse[i][j];
        }
        if (s == 0) {
            rank = i;
            break;
        }
    }

    bool works = 0;
    int ans = 0;
    for (int i = 0; i < rank; ++i) {
        for (int j = i; j < S; ++j) {

        }
    }
    if (!works) {
        cout << "NaN\n";
    } else {
        cout << ans << '\n';
    }

    return 0;
}
