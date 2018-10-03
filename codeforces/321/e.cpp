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
using vvi = vector<vi>;

constexpr ll INF = 1e18;

template <typename F>
struct DP {
    vector<ll> before, cur;
    int n;
    F score;

    DP(const vector<ll>& old, F& score):
        before(begin(old), end(old)), cur(old.size()), n((int)old.size() - 1), score(score) {}

    inline int lo(int idx) {
        return 1;
    }

    inline int hi(int idx) {
        return idx;
    }

    void compute(int l, int r, int optl, int optr) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        pair<ll, int> best = {INF, -1};

        for (int k = max(lo(mid), optl); k <= min(hi(mid), optr); ++k) {
            best = min(best, {before[k - 1] + score(k, mid), k});
        }

        cur[mid] = best.first;
        int opt = best.second;

        compute(l, mid - 1, optl, opt);
        compute(mid + 1, r, opt, optr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));
    string buf;
    getline(cin, buf);
    for (int i = 1; i <= n; ++i) {
        getline(cin, buf);
        for (int j = 1; j <= n; ++j) {
            // 1 -> 0, 2 -> 2, 3 -> 4,
            cost[i][j] = buf[2 * (j - 1)] - '0';
            cost[i][j] += cost[i][j - 1];
            cost[i][j] += cost[i - 1][j];
            cost[i][j] -= cost[i - 1][j - 1];
        }
    }

    auto score = [&cost](int i, int j) {
        return cost[j][j] - cost[i - 1][j] - cost[j][i - 1] + cost[i - 1][i - 1];
    };

    vector<ll> old(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        old[i] = score(1, i);

    for (int i = 2; i <= k; ++i) {
        DP divide_and_conq(old, score);
        divide_and_conq.compute(1, n, 1, n);
        swap(old, divide_and_conq.cur);
    }

    cout << (old[n] >> 1) << '\n';

    return 0;
}
