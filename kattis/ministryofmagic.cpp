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

    int c, p;
    cin >> c >> p;
    vector<int> v(p);
    int tot_votes = 0;
    vector<vector<int>> ballot(p, vector<int>(c));

    for (int i = 0; i < p; ++i) {
        cin >> v[i];
        tot_votes += v[i];
        for (int j = 0; j < c; ++j) {
            cin >> ballot[i][j];
            --ballot[i][j];
        }
    }

    vector<int> ptrs(p, 0);
    vector<bool> dead(c, false);

    while (true) {
        vector<int> votes(c, 0);

        // printf("NEW ROUND\n");
        for (int i = 0; i < p; ++i) {
            while (dead[ballot[i][ptrs[i]]])
                ++ptrs[i];

            // printf("Ballot %d voting for %d\n", i, ballot[i][ptrs[i]]);
            votes[ballot[i][ptrs[i]]] += v[i];
        }

        int cand = -1;
        int loser = 1e9 + 8;
        for (int i = 0; i < c; ++i) {
            if (dead[i]) continue;
            if (2 * votes[i] > tot_votes) {
                cout << (i + 1) << '\n';
                return 0;
            }

            if (votes[i] < loser) {
                loser = votes[i];
                cand = i;
            }
        }

        dead[cand] = true;
    }

    return 0;
}
