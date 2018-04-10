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
#include <numeric>
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

constexpr int W = 3;
constexpr int H = 67;

bool used[H][W];

pii gen_move() {
    bool found = false;
    pii res = {1, 1};
    for (int i = 1; i + 1 < H; ++i) {
        int score = 9;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                score -= used[i + dx][1 + dy];
            }
        }

        if (score) {
            if (!found) {
                res = {i, 1};
                found = true;
            } else {
                if (rand() % 2) {
                    res = {i, 1};
                }
            }
        }
    }
    
    assert(found);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, A, x, y;
    cin >> T;
    while (T-- > 0) {
        cin >> A;
        memset(used, 0, sizeof(used));
        int score = 0;
        bool solved = false;
        while (score < W * H) {
            pii move = gen_move();
            cout << (move.first + 1) << ' ' << (move.second + 1) << endl;
            cout.flush();

            cin >> x >> y;
            if (x == 0 and y == 0) {
                solved = true;
                break;
            } else if (x == -1 and y == -1) {
                break;
            }

            --x; --y;
            if (!used[x][y])
                ++score;

            used[x][y] = true;
        }

        if (!solved)
            break;
    }
    
    return 0;
}
