/*
ID: rednano1
PROG: frameup
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
char grid[33][33];

// left top right bot
int dim[26][4];
bool valid[26];
// prereq [x][y] means that x is a prereq of y
bool prereq[26][26];
bool used[26];

// returns if qi, qj is a spot on the frame x
bool on_square(int x, int qi, int qj) {
    int l = dim[x][0];
    int t = dim[x][1];
    int r = dim[x][2];
    int b = dim[x][3];

    return ((qi == t or qi == b) and (l <= qj and qj <= r)) 
        or ((qj == l or qj == r) and (t <= qi and qi <= b));
}

string cur = "";
int num_frames = 0;
void dfs(ofstream& fout) {
    if ((int) cur.size() == num_frames) {
        fout << cur << '\n';
        return;
    }

    for (int x = 0; x < 26; ++x) {
        bool can_use = !used[x] and valid[x];
        for (int y = 0; y < 26; ++y) {
            if (prereq[y][x] and !used[y]) {
                can_use = false;
                break;
            }
        }

        if (!can_use) continue;
        used[x] = true;
        cur += (x + 'A');
        dfs(fout);
        used[x] = false;
        cur = cur.substr(0, cur.size() - 1);
    }
}

int main() {
    ifstream fin("frameup.in");
    ofstream fout("frameup.out");

    fin >> n >> m;
    for (int i = 0; i < n; ++i) {
        fin >> grid[i];
    }
    fin.close();

    memset(dim, -1, sizeof(dim));
    memset(valid, 0, sizeof(valid));
    memset(prereq, 0, sizeof(prereq));

    for (int i = 0; i < 26; ++i)
        used[i] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') {
                int ind = grid[i][j] - 'A';
                dim[ind][0] = dim[ind][0] == -1 ? j : min(j, dim[ind][0]);
                dim[ind][1] = dim[ind][1] == -1 ? i : min(i, dim[ind][1]);
                dim[ind][2] = dim[ind][2] == -1 ? j : max(j, dim[ind][2]);
                dim[ind][3] = dim[ind][3] == -1 ? i : max(i, dim[ind][3]);
                if (!valid[ind]) ++num_frames;
                valid[ind] = true;
                used[ind] = false;
            }
        }
    }

    /*
    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << on_square(k, i, j);
            }
            cout << '\n';
        }
        cout << '\n';
    }
    */

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') {
                for (int k = 0; k < 26; ++k) {
                    char kc = k + 'A';
                    if (valid[k] and grid[i][j] != kc and on_square(k, i, j)) {
                        prereq[k][grid[i][j] - 'A'] = true;
                    }
                }
            }
        }
    }

    dfs(fout);

    return 0;
}
