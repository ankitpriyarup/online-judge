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
    cin >> n >> m;

    vector<vector<int>> players(1003);
    for (int i = 0; i < n; ++i) {
        int k, note;
        cin >> k;
        while (k-- > 0) {
            cin >> note;
            players[note].push_back(i);
        }
    }

    constexpr int INF = 1e9 + 7;
    vector<int> dp(n, 0);

    for (int i = 0; i < m; ++i) {
        int min_prev = *min_element(begin(dp), end(dp));

        int note;
        cin >> note;

        vector<int> dp_new(n, INF);
        for (int idx : players[note]) {
            dp_new[idx] = min(min_prev + 1, dp[idx]);
        }

        swap(dp, dp_new);
    }

    cout << *min_element(begin(dp), end(dp)) << '\n';
    return 0;
}
