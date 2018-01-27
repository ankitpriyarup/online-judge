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

constexpr int MAXN = 1003;
constexpr int INF = 1e9;
int n, x;
int ans;
bool used[14];
set<int> s;

void dfs(const vector<int>& order, int pos, int score = 0) {
    if (pos == x) {
        ans = min(ans, score);
        return;
    }

    if (score > ans) return;

    for (int i = 0; i < x; ++i) {
        if (!used[i]) {
            used[i] = true;

            auto it = s.insert(order[i]).first;
            auto before = prev(it);
            auto after = next(it);

            dfs(order, pos + 1, score + *after - *before - 2);

            s.erase(it);
            used[i] = false;
        }
    }
}


/*
int score(const vector<int>& order) {
    memset(grid, 0, sizeof(grid));
    int destroyed = 0;

    set<int> used;
    used.insert(0);
    used.insert(n + 1);

    for (int v : order) {
        auto it = used.insert(v).first;
        auto before = prev(it);
        auto after = next(it);

        destroyed += *after - *before - 2;
    }

    return destroyed;
}o*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    vector<int> switches(x);
    for (int i = 0; i < x; ++i) {
        cin >> switches[i];
    }

    sort(begin(switches), end(switches));
    ans = n * n * n;
    s.insert(0);
    s.insert(n + 1);
    dfs(switches, 0);

    printf("%d", ans);
    return 0;
}
