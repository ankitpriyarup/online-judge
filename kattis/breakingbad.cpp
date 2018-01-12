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

constexpr int MAXN = 100005;
int n, m;
string names[MAXN];
map<string, vector<string> > graph;
map<string, int> vis;
bool poss;

void dfs(const string& s, int color) {
    if (vis.find(s) != end(vis)) {
        if (vis[s] != color)
            poss = false;

        return;
    }

    if (!poss)
        return;

    vis[s] = color;
    for (const string& t : graph[s]) {
        dfs(t, 3 - color);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    cin >> m;
    string a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    poss = true;
    for (int i = 0; i < n; ++i) {
        if (vis.find(names[i]) == end(vis))
            dfs(names[i], 1);
    }

    if (!poss) {
        printf("impossible\n");
    } else {
        for (int i = 0; i < n; ++i) {
            if (vis[names[i]] == 1)
                cout << names[i] << ' ';
        }
        cout << '\n';

        for (int i = 0; i < n; ++i) {
            if (vis[names[i]] == 2)
                cout << names[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
