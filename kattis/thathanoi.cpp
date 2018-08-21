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

    vector<vector<int>> state(3);
    int max_disk = 1;
    for (int k = 0; k < 3; ++k) {
        int m;
        scanf(" %d", &m);

        state[k].assign(m, 0);

        for (int i = 0; i < m; ++i) {
            scanf(" %d", &state[k][i]);
            max_disk = max(max_disk, state[k][i]);
        }

        reverse(begin(state[k]), end(state[k]));
        for (int i = 0; i + 1 < state[k].size(); ++i) {
            if (state[k][i] >= state[k][i + 1]) {
                printf("No\n");
                return 0;
            }
        }
    }
    
    ll so_far = 0;
    for (int i = max_disk; i >= 1; --i) {
        // max disk is either bottom of 0 or bottom of 2
        if (!state[0].empty() and state[0].back() == i) {
            state[0].pop_back();
            swap(state[1], state[2]);
        } else if (!state[2].empty() and state[2].back() == i) {
            // takes 2^(n - 1) moves to make it this far
            state[2].pop_back();
            so_far += (1LL << (i - 1LL));
            swap(state[0], state[1]);
        } else {
            printf("No\n");
            return 0;
        }
    }

    printf("%lld\n", (1LL << max_disk) - so_far - 1);

    return 0;
}
