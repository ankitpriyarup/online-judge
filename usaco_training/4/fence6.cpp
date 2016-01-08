/*
ID: rednano1
PROG: fence6
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N;
map<vector<int>, int> v_lookup;
int adjmat[101][101];
int dists[101][101];

int get_index(const vector<int> &v) {
    if (v_lookup.find(v) == v_lookup.end()) {
        int x = v_lookup.size();
        v_lookup[v] = x;
    }

    return v_lookup[v];
}

void fw() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dists[i][k] > -1 and dists[k][j] > -1) {
                    int new_dist = dists[i][k] + dists[k][j];
                    dists[i][j] = (dists[i][j] == -1) ? new_dist : min(dists[i][j], new_dist);
                }
            }
        }
    }
}

int main() {
    ifstream fin("fence6.in");
    ofstream fout("fence6.out");

    int S, L, N1, N2;
    int x, y;

    fin >> N;

    memset(adjmat, -1, sizeof(adjmat));
    for (int i = 0; i < N; ++i) {
        fin >> S >> L >> N1 >> N2;
        vector<int> v1;
        vector<int> v2;

        v1.push_back(S);
        v2.push_back(S);

        for (int i = 0; i < N1; ++i) {
            fin >> x;
            v1.push_back(x);
        }

        for (int i = 0; i < N2; ++i) {
            fin >> x;
            v2.push_back(x);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        x = get_index(v1);
        y = get_index(v2);
        adjmat[x][y] = adjmat[y][x] = L;
        adjmat[x][x] = adjmat[y][y] = 0;
    }
    fin.close();

    /*
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << adjmat[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    int ans = 255 * 100;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (adjmat[i][j] > -1) {
                memcpy(dists, adjmat, sizeof(dists));
                dists[i][j] = dists[j][i] = -1;
                fw();
                if (dists[i][j] == -1) continue;
                ans = min(ans, dists[i][j] + adjmat[i][j]);
            }
        }
    }

    fout << ans << '\n';
    return 0;
}
