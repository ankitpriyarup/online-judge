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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    vector<int> state(n, 0);
    bool poss = true;
    for (int j = 0; j < n; ++j) {
        int open = 0;
        int close = 0;
        for (int i = 0; i < n; ++i) {
            if (grid[i][j] == '(')
                ++open;
            else
                ++close;
        }

        for (int k = 0; k < open; ++k) {
            state[k] += 1;
        }
        for (int k = open; k < n; ++k) {
            state[k] -= 1;
        }

        sort(begin(state), end(state));
        if (state[0] < 0) {
            poss = false;
            break;
        }
    }

    poss &= state.back() == 0;

    cout << (poss ? "Yes" : "No") << '\n';

    return 0;
}
