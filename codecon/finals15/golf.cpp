#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;
bool adjmat[10][10];
// find the number of paths from node i of length j that end at 9
int dp[11][11];

int grid[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
int dx[] = {1, 2, -1, -2, 1, 2, -1, -2};
int dy[] = {2, 1, 2, 1, -2, -1, -2, -1};

// Set up the graph
void setup() {
    memset(adjmat, 0, sizeof(adjmat));
    for (int x1 = 0; x1 < 4; ++x1) {
        for (int y1 = 0; y1 < 3; ++y1) {
            if (grid[x1][y1] == -1) {
                continue;
            }
            for (int d = 0; d < 8; ++d) {
                int x2 = x1 + dx[d];
                int y2 = y1 + dy[d];

                if (x2 >= 0 and y2 >= 0 and x2 < 4 and y2 < 3 and grid[x2][y2] != -1) {
                    int v1 = grid[x1][y1];
                    int v2 = grid[x2][y2];
                    adjmat[v1][v2] = 1;
                    adjmat[v2][v1] = 1;
                }
            }
        }
    }
}

int main() {
    setup();
    cin >> N;

    memset(dp, 0, sizeof(dp));
    dp[9][0] = 1;
    for (int len = 1; len <= 10; ++len) {
        for (int start = 0; start < 10; ++start) {
            for (int next = 0; next < 10; ++next) {
                if (adjmat[start][next]) {
                    dp[start][len] += dp[next][len - 1];
                }
            }
        }
    }

    cout << dp[1][N] << '\n';

    return 0;
}
