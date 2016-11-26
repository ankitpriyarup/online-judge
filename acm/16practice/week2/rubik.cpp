#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool cube1[5][5][5];
bool cube2[5][5][5];

bool fit(int x_offset, int y_offset, int z_offset) {
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            for (int z = 0; z < 5; ++z) {
                int nx = x + x_offset;
                int ny = y + y_offset;
                int nz = z + z_offset;

                bool hasCell = 0 <= nx && nx < 5 
                            && 0 <= ny && ny < 5 
                            && 0 <= nz && nz < 5 
                            && cube2[nx][ny][nz];

                if (!(cube1[x][y][z] ^ hasCell)) {
                    return false;
                }
            }
        }
    }

    return true;
}

/* return if a cube can be made by dropping cube2 down onto cube1 */
bool fit() {
    for (int x_offset = -5; x_offset <= 5; ++x_offset) {
        for (int y_offset = -5; y_offset <= 5; ++y_offset) {
            for (int z_offset = -5; z_offset <= 5; ++z_offset) {
                if (fit(x_offset, y_offset, z_offset)) {
                    return true;
                }
            }
        }
    }

    return false;
}

void flip_forward() {
    bool cubetemp[5][5][5];
    memcpy(cubetemp, cube2, sizeof(cubetemp));

    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            for (int z = 0; z < 5; ++z) {
                cube2[x][y][z] = cubetemp[y][5 - x - 1][z];
            }
        }
    }
}

void flip_right () {
    bool cubetemp[5][5][5];
    memcpy(cubetemp, cube2, sizeof(cubetemp));

    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            for (int z = 0; z < 5; ++z) {
                cube2[x][y][z] = cubetemp[5 - z - 1][y][x];
            }
        }
    }
}

void rotate_right() {
    bool cubetemp[5][5][5];
    memcpy(cubetemp, cube2, sizeof(cubetemp));

    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            for (int z = 0; z < 5; ++z) {
                cube2[x][y][z] = cubetemp[x][z][5 - y - 1];
            }
        }
    }
}

void print_cube() {
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            for (int z = 0; z < 5; ++z) {
                cout << (cube2[x][y][z] ? '1' : '0');
            }
            cout << '\n';
        }
        cout << '\n';
    }
}

int main() {
    int T;
    string part1, part2;
    cin >> T;

    while (T-- > 0) {
        memset(cube1, 0, sizeof(cube1));
        memset(cube2, 0, sizeof(cube2));

        int count = 0;
        for (int i = 0; i < 5; ++i) {
            cin >> part1 >> part2;
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < part1[j] - '0'; ++k) {
                    cube1[k][i][j] = 1;
                    ++count;
                }

                for (int k = 0; k < part2[j] - '0'; ++k) {
                    cube2[k][i][j] = 1;
                    ++count;
                }
            }
        }

        bool works = false;
        if (count == 125) {
            // for each face, handle all 4 rotations
            for (int face = 0; face < 4; ++face) {
                for (int rot = 0; rot < 4; ++rot) {
                    if (fit()) {
                        works = true;
                        break;
                    }
                    rotate_right();
                }

                flip_forward();
            }

            flip_right();
            for (int rot = 0; rot < 4; ++rot) {
                if (fit()) {
                    works = true;
                    break;
                }
                rotate_right();
            }

            flip_right();
            flip_right();

            for (int rot = 0; rot < 4; ++rot) {
                if (fit()) {
                    works = true;
                    break;
                }
                rotate_right();
            }
        }

        cout << (works ? "Yes" : "No") << '\n';
    }
    return 0;
}
