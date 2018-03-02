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

struct state {
    vector<vector<int> > board;
    bool move;

    state(): board(vector<vector<int>>(3, vector<int>(3, 0))), move(false) {};
    state(vector<vector<int>>& s, bool move): board(begin(s), end(s)), move(move) {};

    bool done() const {
        for (int i = 0; i < 3; ++i) {
            int v = board[i][0];
            if (!v) continue;
            bool valid = true;
            for (int j = 0; j < 3; ++j) {
                valid &= board[i][j] == v;
            }

            if (valid) return true;
        }

        for (int j = 0; j < 3; ++j) {
            int v = board[0][j];
            if (!v) continue;
            bool valid = true;
            for (int i = 0; i < 3; ++i) {
                valid &= board[i][j] == v;
            }

            if (valid) return true;
        }

        if (board[0][0] == board[1][1] and board[1][1] == board[2][2] and board[0][0] != 0)
            return true;

        if (board[2][0] == board[1][1] and board[1][1] == board[0][2] and board[2][0] != 0)
            return true;

        return false;
    }

    vector<state> follow() {
        vector<state> children;
        if (done())
            return children;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != 0) {
                    continue;
                }

                board[i][j] = move + 1;
                children.emplace_back(board, !move);
                board[i][j] = 0;
            }
        }

        return children;
    }

    ll hash() const {
        ll res = 0LL;
        ll base = 1LL;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                res += base * board[i][j];
                base *= 3LL;
            }
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    set<ll> hashes;

    queue<state> q;
    q.push(state());
    hashes.insert(q.front().hash());

    while (!q.empty()) {
        for (state& child : q.front().follow()) {
            ll h = child.hash();
            if (hashes.find(h) == end(hashes)) {
                hashes.insert(h);
                q.push(child);
            }
        }

        q.pop();
    }

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        char c;
        vector<vector<int>> board(3, vector<int>(3, 0));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                scanf(" %c", &c);
                if (c == 'X')
                    board[i][j] = 1;
                else if (c == 'O')
                    board[i][j] = 2;
            }
        }

        ll h = state(board, false).hash();
        printf("%s\n", hashes.count(h) ? "yes" : "no");
    }
    
    return 0;
}
