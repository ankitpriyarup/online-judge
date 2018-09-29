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

    vector<vector<int>> grundy(101, vector<int>(101, 0));

    for (int i = 0; i <= 100; ++i) {
        grundy[i][0] = grundy[0][i] = grundy[i][i] = 1000000;
    }
    grundy[0][0] = 0;

    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (i == j) continue;

            set<int> s;
            for (int u = 1; u <= max(i, j); ++u) {
                if (u <= i)
                    s.insert(grundy[i - u][j]);
                if (u <= j)
                    s.insert(grundy[i][j - u]);
                if (u <= i and u <= j)
                    s.insert(grundy[i - u][j - u]);
            }

            while (s.count(grundy[i][j]))
                ++grundy[i][j];
        }
    }

    int n;
    cin >> n;
    int state = 0;
    int x, y;
    while (n-- > 0) {
        cin >> x >> y;
        state ^= grundy[x][y];
    }
    cout << (state == 0 ? "N" : "Y");

    return 0;
}
