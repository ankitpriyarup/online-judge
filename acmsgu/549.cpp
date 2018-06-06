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

constexpr int MAXM = 4003;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    scanf(" %d %d", &n, &k);
    vector<vector<ll>> bells(MAXM);
    int m, c;
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &m, &c);
        bells[m].push_back(c);
    }

    for (int i = 0; i < MAXM; ++i) {
        sort(begin(bells[i]), end(bells[i]));
        reverse(begin(bells[i]), end(bells[i]));
        int len = bells[i].size();
        for (int j = 1; j < len; ++j) {
            bells[i][j] += bells[i][j - 1];
        }
    }

    sort(begin(bells), end(bells), [](const vector<ll>& a, const vector<ll>& b) {
        return a.size() > b.size();
    });

    int ans = bells[k - 1].size();
    if (ans == 0) {
        printf("%d %d\n", 0, 0);
        return 0;
    }

    sort(begin(bells), end(bells), [&](const vector<ll>& a, const vector<ll>& b) {
        if (a.size() < ans or b.size() < ans) {
            return a.size() > b.size();
        } else {
            return a[ans - 1] > b[ans - 1];
        }
    });

    ll total_cost = 0;
    for (int i = 0; i < k; ++i) {
        total_cost += bells[i][ans - 1];
    }

    printf("%d %lld\n", ans, total_cost);

    return 0;
}
