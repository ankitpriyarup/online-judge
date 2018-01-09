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

constexpr int MAXN = 505;
int n, b, r;
int bx[MAXN], by[MAXN], rx[MAXN], ry[MAXN];

ll dist(int b_ind, int r_ind) {
    ll xd = bx[b_ind] - rx[r_ind];
    ll yd = by[b_ind] - ry[r_ind];

    return xd * xd + yd * yd;
}

bool find(const vector<vector<int> >& graph, vector<int>& match, vector<bool>& seen, int j) {
    if (match[j] == -1) return true;

    seen[j] = true;
    int di = match[j];
    for (auto& e : graph[di]) {
        if (!seen[e] and find(graph, match, seen, e)) {
            match[e] = di;
            return true;
        }
    }

    return false;
}

int dfs_matching(const vector<vector<int> >& graph, int n, int m) {
    vector<int> match;
    vector<bool> seen;
    match.assign(m, -1);
    for (int i = 0; i < n; ++i) {
        seen.assign(m, 0);
        for (auto& j : graph[i]) {
            if (find(graph, match, seen, j)) {
                match[j] = i;
                break;
            }
        }
    }

    return m - count(begin(match), end(match), -1);
}

bool works(ld ans) {
    // printf("Trying dist %.2Lf\n", ans);
    vector<vector<int> > graph(b);
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < r; ++j) {
            if (dist(i, j) <= ans * ans) {
                // printf("Edge from blue %d to red %d\n", i, j);
                graph[i].push_back(j);
            }
        }
    }

    int vert_cover = dfs_matching(graph, b, r);
    // printf("Vertex cover: %d, max set: %d\n", vert_cover, b + r - vert_cover);
    return b + r - vert_cover >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &b, &r);
    for (int i = 0; i < b; ++i) {
        scanf("%d %d", bx + i, by + i);
    }
    for (int i = 0; i < r; ++i) {
        scanf("%d %d", rx + i, ry + i);
    }

    ld lo = 0.0L;
    ld hi = 1.0e9;
    for (int iter = 0; iter < 100; ++iter) {
        ld mid = (lo + hi) / 2.0L;
        if (works(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%.17Lf\n", lo);
    return 0;
}
