#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, -1, 0, 1};

vector<int> gen_moves() {
    vector<int> moves(9, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int ind = 3 * i + j;
            int mask = 1 << ind;
            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (0 <= nx and nx < 3 and 0 <= ny and ny < 3) {
                    mask |= 1 << (3 * nx + ny);
                }
            }

            moves[3 * i + j] = mask;
        }
    }

    return moves;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> moves = gen_moves();

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        char grid[5];
        int mask = 0;
        for (int i = 0; i < 3; ++i) {
            scanf("%s", grid);
            for (int j = 0; j < 3; ++j) {
                int ind = 3 * i + j;
                if (grid[j] == '*')
                    mask |= (1 << ind);
            }
        }

        int ans = 10;
        for (int move_mask = 0; move_mask < (1 << 9); ++move_mask) {
            int move = 0;
            for (int i = 0; i < 9; ++i) {
                if (move_mask & (1 << i)) {
                    move ^= moves[i];
                }
            }

            if (move == mask)
                ans = min(ans, __builtin_popcount(move_mask));
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
