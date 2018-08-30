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

    constexpr int MAXV = 100001;
    int n;
    scanf(" %d", &n);

    ll u, v;
    vector<vector<pair<ll, ll>>> by_score(MAXV);

    for (int i = 0; i < n; ++i) {
        scanf(" %lld %lld", &u, &v);
        by_score[u + v].emplace_back(u, v);
    }

    ll ans = 0;
    for (int i = 0; i < MAXV; ++i) {
        if (by_score[i].empty())
            continue;

        // printf("Trying score %d\n", i);
        sort(begin(by_score[i]), end(by_score[i]));

        int m = by_score[i].size();

        vector<ll> pref2(m);
        pref2[0] = by_score[i][0].second;
        for (int j = 1; j < m; ++j) {
            pref2[j] = pref2[j - 1] + by_score[i][j].second;
        }

        vector<ll> suff1(m);
        suff1[m - 1] = by_score[i][m - 1].first;
        for (int j = m - 2; j >= 0; --j) {
            suff1[j] = suff1[j + 1] + by_score[i][j].first;
        }

        /*
        printf("pref:\n");
        for (int j = 0; j < m; ++j) {
            printf("%lld ", pref2[j]);
        }
        printf("\nsuff:\n");
        for (int j = 0; j < m; ++j) {
            printf("%lld ", suff1[j]);
        }
        printf("\n");
        */

        for (int j = 0; j + 1 < m; ++j) {
            ans = max(ans, min(pref2[j], suff1[j + 1]));
        }
    }

    printf("%lld\n", ans);

    return 0;
}
