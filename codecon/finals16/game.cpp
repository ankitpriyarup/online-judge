#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 

using namespace std;

int row, col;
char grid[102][102];

int X[2], C[2], T[2], S[2];

int diagx[] = {1, 1, -1, -1};
int diagy[] = {-1, 1, -1, 1};

int cardx[] = {1, 0, -1, 0};
int cardy[] = {0, 1, 0, -1};

bool found_x(int i, int j) {
    bool found = grid[i][j] == 'X';
    for (int d = 0; d < 4; ++d) {
        found &= grid[i + diagx[d]][j + diagy[d]] == 'X';
    }

    return found;
}

bool found_c(int i, int j) {
    bool found = true;
    for (int d = 0; d < 4; ++d) {
        found &= grid[i + diagx[d]][j + diagy[d]] == 'C';
    }

    for (int d = 0; d < 4; ++d) {
        found &= grid[i + cardx[d]][j + cardy[d]] == 'C';
    }

    return found;
}

bool found_t(int i, int j) {
    bool found = grid[i][j] == 'T';
    for (int d = -1; d <= 1; ++d) {
        found &= grid[i + 1][j + d] == 'T';
        found &= grid[i + d][j + 1] == 'T';
    }

    return found;
}

bool found_s(int i, int j) {
    bool found = grid[i][j] == 'S';
    for (int d = 0; d < 4; ++d) {
        found &= grid[i + diagx[d]][j + diagy[d]] == 'S';
    }

    for (int d = 0; d < 4; ++d) {
        found &= grid[i + cardx[d]][j + cardy[d]] == 'S';
    }

    return found;
}

void move_it(char piece, char dir, int G) {
    int* target;
    if (piece == 'X') {
        target = &*X;
    } else if (piece == 'C') {
        target = &*C;
    } else if (piece == 'T') {
        target = &*T;
    } else {
        target = &*S;
    }

    switch (dir) {
        case 'U':
            target[0] -= G;
            break;
        case 'D':
            target[0] += G;
            break;
        case 'L':
            target[1] -= G;
            break;
        case 'R':
            target[1] += G;
            break;
    }
}

bool hit_x(int i, int j) {
    bool hit = (i == X[0] and j == X[1]);
    for (int d = 0; d < 4; ++d) {
        hit |= (i == (X[0] + diagx[d])) and (j == (X[1] + diagy[d]));
    }

    return hit;
}

bool c_intersect(int a, int b) {
    bool hit = false;
    for (int d = 0; d < 4; ++d) {
        hit |= hit_x(a + diagx[d], b + diagy[d]);
    }

    for (int d = 0; d < 4; ++d) {
        hit |= hit_x(a + cardx[d], b + cardy[d]);
    }

    return hit;
}

bool t_intersect() {
    bool hit = hit_x(T[0], T[1]);
    for (int d = -1; d <= 1; ++d) {
        hit |= hit_x(T[0] + 1, T[1] + d);
        hit |= hit_x(T[0] + d, T[1] + 1);
    }

    return hit;
}

bool s_intersect() {
    return hit_x(S[0], S[1]) | c_intersect(S[0], S[1]);
}

int main() {
    cin >> row >> col;
    for (int i = 0; i < row; ++i) {
        cin >> grid[i];
    }

    // Find the centers of each piece
    for (int i = 1; i < row - 1; ++i) {
        for (int j = 1; j < col - 1; ++j) {
            // find the centers for each piece
            if (grid[i][j] == 'X' and found_x(i, j)) {
                X[0] = i;
                X[1] = j;
            }

            if (grid[i - 1][j] == 'C' and found_c(i, j)) {
                C[0] = i;
                C[1] = j;
            }

            if (grid[i][j] == 'T' and found_t(i, j)) {
                T[0] = i;
                T[1] = j;
            }

            if (grid[i][j] == 'S' and found_s(i, j)) {
                S[0] = i;
                S[1] = j;
            }
        }
    }

    int Q;
    cin >> Q;
    string move;
    int ans = 0;
    while (Q-- > 0) {
        for (int i = 0; i < 4; ++i) {
            cin >> move;
            char piece = move[0];
            char dir = move[1];
            int G = stoi(move.substr(2, string::npos));
            
            move_it(piece, dir, G);
        }

        int score = 0;
        if (!c_intersect(C[0], C[1])) {
           score++;
        }

        if (!t_intersect()) {
            score++;
        }

        if (!s_intersect()) {
            score++;
        }

        if (score == 3) {
            ans += 1;
        }

        ans += score;
        ans--;
    }

    cout << ans << '\n';

    return 0;
}
