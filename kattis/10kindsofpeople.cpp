#include <iostream>

using namespace std;

char field[1003][1003];
pair<int, int> union_find[1003][1003];

pair<int, int> find(int x1, int y1) {
    pair<int, int> parent = union_find[x1][y1];
    while (union_find[parent.first][parent.second] != parent) {
        parent = union_find[parent.first][parent.second];
    }

    union_find[x1][y1] = parent;

    return parent;
}

void join(int x1, int y1, int x2, int y2) {
    pair<int, int> parent1 = find(x1, y1);
    pair<int, int> parent2 = find(x2, y2);
    if (parent1 != parent2)
        union_find[parent1.first][parent1.second] = parent2;
}

string find_path(int r1, int c1, int r2, int c2) {
    if (find(r1, c1) == find(r2, c2)) {
        return field[r1][c1] == '1' ? "decimal" : "binary";
    } else {
        return "neither";
    }
}

int r, c;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return 0 <= x and x < r
       and 0 <= y and y < c;
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; ++i) {
        cin >> field[i];
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            union_find[i][j] = make_pair(i, j);
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if (valid(nx, ny) and field[i][j] == field[nx][ny]) {
                    join(i, j, nx, ny);
                }
            }
        }
    }

    int q;
    cin >> q;
    int r1, c1, r2, c2;
    while (q-- > 0) {
        cin >> r1 >> c1 >> r2 >> c2;
        --r1;
        --r2;
        --c1;
        --c2;
        cout << find_path(r1, c1, r2, c2) << '\n';
    }
}
