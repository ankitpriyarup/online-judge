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
using vi = vector<int>;

constexpr int DEBUG = 0;

struct turn {
    int guess, move, reveal;
};

constexpr int bounds[3][2] = {{0, 6}, {6, 12}, {12, 21}};
vector<turn> turns;

vi gen_ans(int my_hand) {
    vi res;
    for (int p = bounds[0][0]; p < bounds[0][1]; ++p) {
        if ((1 << p) & my_hand) continue;
        for (int w = bounds[1][0]; w < bounds[1][1]; ++w) {
            if ((1 << w) & my_hand) continue;
            for (int r = bounds[2][0]; r < bounds[2][1]; ++r) {
                if ((1 << r) & my_hand) continue;
                res.push_back((1 << p) | (1 << w) | (1 << r));
            }
        }
    }

    return res;
}

vi gen_fours(int my_hand) {
    vi res;
    for (int i = 0;     i < 21; ++i) {
        if ((1 << i) & my_hand) continue;
    for (int j = i + 1; j < 21; ++j) {
        if ((1 << j) & my_hand) continue;
    for (int k = j + 1; k < 21; ++k) {
        if ((1 << k) & my_hand) continue;
    for (int l = k + 1; l < 21; ++l) {
        if ((1 << l) & my_hand) continue;
                    res.push_back((1 << i) | (1 << j) | (1 << k) | (1 << l));
                }
            }
        }
    }

    return res;
}

int read() {
    int n;
    cin >> n;
    int my_hand = 0;
    char c;
    for (int i = 0; i < 5; ++i) {
        cin >> c;
        my_hand |= (1 << (c - 'A'));
    }

    char person, weapon, room;
    for (int i = 0; i < n; ++i) {
        cin >> person >> weapon >> room;
        person -= 'A';
        weapon -= 'A';
        room -= 'A';

        c = '-';
        int move = -1;
        while (move < 2 and c == '-') {
            ++move;
            cin >> c;
        }

        int guess_mask = (1 << person) | (1 << weapon) | (1 << room);
        turns.push_back({guess_mask, move, c == '-' ? -2 : (c == '*' ? -1 : c - 'A')});
    }

    return my_hand;
}

bool attempt(int p1, int p2, int p3, int p4, int& res) {
    int hands[4] = {p1, p2, p3, p4};
    int leader = 0;
    for (const turn& t : turns) {
        int shower = (leader + t.move + 1) & 3;
        if (t.reveal == -2) {
            for (int k = 0; k < 3; ++k) {
                if ((hands[(leader + 1 + k) & 3] & t.guess) != 0) {
                    return false;
                }
            }
        } else {
            for (int d = 0; d < t.move; ++d) {
                int skipper = (leader + d + 1) & 3;
                if ((hands[skipper] & t.guess) != 0) {
                    return false;
                }
            }
            if (t.reveal >= -1 and (hands[shower] & t.guess) == 0) {
                return false;
            }

            if (t.reveal >= 0) {
                assert(leader == 0 or shower == 0);
                if ((hands[shower] & (1 << t.reveal)) == 0) {
                    return false;
                }
            }
        }

        leader = (leader + 1) & 3;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int p1 = read();
    vi ans_masks = gen_ans(p1);
    int full = (1 << 21) - 1;
    int options = 0;
    for (const int& ans : ans_masks) {
        if (p1 & ans) continue;
        vi f1 = gen_fours(p1 | ans);
        for (const int& p3 : f1) {
            if (p3 & (p1 | ans)) continue;
            vi f2 = gen_fours(p1 | p3 | ans);
            for (const int& p4 : f2) {
                if (p4 & (p1 | p3 | ans)) continue;
                int p2 = full ^ p1 ^ p3 ^ p4 ^ ans;

                if (attempt(p1, p2, p3, p4, options)) {
                    options |= ans;
                }
            }
        }
    }

    string res(3, '?');
    for (int k = 0; k < 3; ++k) {
        int pc = 0;
        int v = -1;
        for (int i = bounds[k][0]; pc < 2 and i < bounds[k][1]; ++i) {
            if (options & (1 << i)) {
                ++pc;
                v = i;
            }
        }

        if (pc == 1) {
            res[k] = (v + 'A');
        }
    }

    cout << res << '\n';
    return 0;
}
