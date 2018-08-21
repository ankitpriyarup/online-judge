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
    while (scanf(" %d %d", &n, &m) == 2) {
        vector<char> state(n + 1, 0);
        vector<int> moves(m);
        for (int i = 0; i < m; ++i)
            scanf(" %d", &moves[i]);
        for (int i = 1; i <= n; ++i) {
            bool can_win = false;
            for (int x : moves) {
                state[i] |= (x <= i and !state[i - x]);
            }
        }

        printf("%s wins\n", state[n] ? "Stan" : "Ollie");
    }
    
    return 0;
}
