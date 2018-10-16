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

    int n, m;
    while (cin >> n >> m) {
        if (n == 0) break;
        vector<int> heads(n), heights(m);
        for (int i = 0; i < n; ++i) {
            cin >> heads[i];
        }

        for (int i = 0; i < m; ++i) {
            cin >> heights[i];
        }

        sort(begin(heads), end(heads));
        sort(begin(heights), end(heights));

        bool poss = true;
        int ptr = 0;
        int cost = 0;
        for (int i = 0; i < n; ++i) {
            while (ptr < m and heights[ptr] < heads[i])
                ++ptr;

            if (ptr == m) {
                poss = false;
                break;
            }
            cost += heights[ptr++];
        }

        if (poss) {
            cout << cost << '\n';
        } else {
            cout << "Loowater is doomed!\n";
        }
    }

    return 0;
}
