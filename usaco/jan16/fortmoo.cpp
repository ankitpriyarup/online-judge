#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int N, M;
char grid[202][202];
int blocks_left[202][202];
int blocks_up[202][202][202];

int main() {
    ifstream fin("fortmoo.in");
    ofstream fout("fortmoo.out");

    fin >> N >> M;
    for (int i = 0; i < N; ++i) {
        fin >> grid[i];
    }
    fin.close();

    memset(blocks_left, 0, sizeof(blocks_left));
    memset(blocks_up, -1, sizeof(blocks_up));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'X')
                blocks_left[i][j]++;
            if (j > 0)
                blocks_left[i][j] += blocks_left[i][j - 1];
        }
    }

    /*
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << blocks_left[i][j] << " ";
        }
        cout << '\n';
    }
    */

    long long ans = 0;

    for (int i = 0; i < N; ++i) {
        for (int j1 = 0; j1 < M; ++j1) {
            for (int j2 = j1 + 1; j2 < M; ++j2) {
                // figure out if you can make a rectangle with bottom corners at (i, j1) and (i, j2)
                bool ok = grid[i][j1] != 'X' and grid[i][j2] != 'X';
                if (ok and i > 0 and blocks_up[i - 1][j1][j2] != -1) {
                    blocks_up[i][j1][j2] = 1 + blocks_up[i - 1][j1][j2];
                } else {
                    blocks_up[i][j1][j2] = (ok and blocks_left[i][j1] == blocks_left[i][j2]) ? 0 : -1;
                }

                if ((ok and blocks_left[i][j1] == blocks_left[i][j2]) and blocks_up[i][j1][j2] != -1) {
                    //cout << "Trying rectangle at row " << i << " cols " << j1 << ", " << j2 << '\n';
                    ans = max(ans, (long long) (j2 - j1 + 1) * (blocks_up[i][j1][j2] + 1));
                }

                //cout << "blocks_up[" << i << "][" << j1 << "][" << j2 << "] = " << blocks_up[i][j1][j2] << '\n';
            }
        }
    }

    fout << ans << '\n';
    return 0;
}
