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

    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<vector<pii>>> flights(n, vector<vector<pii>>(k));
    int u, v, d, z;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> d >> z;
        --u; --v; --d;
        flights[d][u].emplace_back(v, z);
    }
    vector<vector<int>> ppl(n, vector<int>(k, 0));
    for (int i = 0; i < k * n; ++i) {
        cin >> u >> d >> z;
        --u; --d;
        ppl[d][u] += z;
    }

    bool poss = true;
    vector<int> cur(k, 0);
    for (int day = 0; day < n; ++day) {
        for (int i = 0; i < k; ++i) {
            cur[i] += ppl[day][i];
        }

        vector<int> nxt(begin(cur), end(cur));
        for (int i = 0; i < k; ++i) {
            for (pii& flight : flights[day][i]) {
                tie(v, z) = flight;
                poss &= cur[i] >= z;
                cur[i] -= z;
                nxt[v] += z;
            }
        }

        swap(cur, nxt);
    }

    cout << (poss ? "optimal" : "suboptimal") << '\n';

    return 0;
}
