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

constexpr int MAXM = 111;
int m;
int a[MAXM], b[MAXM];
vector<pii> graph[7];
int deg[7];

vector<pii> euler_walk(int src) {
    vector<vector<pii>::iterator> its;
    for (int i = 0; i <= 6; ++i) {
        its.push_back(graph[i].begin());
    }

    vector<char> used(m + 1, 0);
    vector<pii> ret, stk;
    stk.emplace_back(src, 0);
    used[0] = true;
    // printf("Source %d\n", src);
    while (!stk.empty()) {
        // printf("Stack top %d %d\n", stk.back().first, stk.back().second);
        auto x = stk.back().first;
        auto& it = its[x], end = graph[x].end();
        while (it != end and used[abs(it->second)]) ++it;
        if (it == end) {
            ret.push_back(stk.back());
            stk.pop_back();
        } else {
            stk.push_back(*it);
            used[abs(it->second)] = true;
        }
    }

    ret.pop_back();

    if ((int)ret.size() < m) {
        ret.clear();
    }

    reverse(begin(ret), end(ret));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf(" %d %d", a + i, b + i);
        graph[a[i]].push_back({b[i], i});
        graph[b[i]].push_back({a[i], -i});
        ++deg[a[i]];
        ++deg[b[i]];
    }

    int num_odds = 0;
    int start = 0;
    for (int i = 0; i <= 6; ++i) {
        // printf("DEG[%d] = %d\n", i, deg[i]);
        if (deg[i] & 1) {
            ++num_odds;
            start = i;
        } else if (deg[i] > 0 and num_odds == 0) {
            start = i;
        }
    }

    if (num_odds != 0 and num_odds != 2) {
        printf("No solution\n");
        return 0;
    }

    vector<pii> res = euler_walk(start);

    if (res.empty()) {
        printf("No solution\n");
    } else {
        for (const auto& p : res) {
            if (p.second < 0) {
                printf("%d -\n", -p.second);
            } else {
                printf("%d +\n", p.second);
            }
        }
    }

    return 0;
}
