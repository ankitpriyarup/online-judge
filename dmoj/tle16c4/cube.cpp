#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int labels[] = {1, 2, 3, 4, 5, 6, 7, 8};
bool exists[10][10];

int edges[12][2] = {
    {1, 2},
    {2, 3},
    {3, 4},
    {1, 4},
    {5, 6},
    {6, 7},
    {7, 8},
    {5, 8},
    {1, 5},
    {2, 6},
    {3, 7},
    {4, 8}
};

int main() {
    int n;
    cin >> n;
    memset(exists, 0, sizeof(exists));
    int u, v;
    for (int i = 0; i < n; ++i) {
        cin >> u >> v;
        exists[u][v] = true;
        exists[v][u] = true;
    }

    bool possible = false;
    // 1 2 3 4 5 6 7 8
    // 1 2 3 4 top square
    // | | | |
    // 5 6 7 8 bot square
    do {
        bool all_exist = true;
        for (int e = 0; e < 12; ++e) {
            int x = labels[edges[e][0] - 1];
            int y = labels[edges[e][1] - 1];

            if (!exists[x][y]) {
                all_exist = false;
                break;
            }
        }

        if (all_exist) {
            possible = true;
            break;
        }
    } while (!possible and next_permutation(labels + 1, labels + 8));

    cout << (possible ? "Ja" : "Nej") << '\n';

    return 0;
}
