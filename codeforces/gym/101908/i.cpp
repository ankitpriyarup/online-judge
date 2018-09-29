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

int moves(const vector<vector<int>>& switches, vector<char>& cur) {
    int on = 0;
    for (char x : cur)
        on += x;

    for (size_t i = 0; i < switches.size(); ++i) {
        for (int light : switches[i]) {
            if (cur[light]) {
                --on;
            } else {
                ++on;
            }

            cur[light] ^= 1;
        }

        if (on == 0) {
            return i + 1;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<char> init(m, 0);
    int k;
    cin >> k;
    int x;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        --x;
        init[x] = 1;
    }

    vector<vector<int>> switches(n);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> x;
            --x;
            switches[i].push_back(x);
        }
    }

    for (int i = 0; i < n; ++i) {
        switches.push_back(switches[i]);
    }

    cout << moves(switches, init) << '\n';
    return 0;
}
