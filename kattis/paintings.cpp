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

constexpr int MAXN = 12;
int n;
vector<string> colors;
vector<string> cur;
vector<string> best;
bool used[MAXN];

map<string, set<string>> banned;
bool printed;
int ways;

void read() {
    cin >> n;
    colors.resize(n);
    cur.clear();
    best.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }
    int m;
    cin >> m;
    banned.clear();
    string a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        banned[a].insert(b);
        banned[b].insert(a);
    }

    ways = 0;
    printed = false;
}

void dfs(int p) {
    if (p == n) {
        ++ways;
        if (!printed) {
            for (int i = 0; i < n; ++i)
                best[i] = cur[i];
            printed = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        if (cur.empty() or banned[cur.back()].find(colors[i]) == end(banned[cur.back()])) {
            used[i] = true;
            cur.push_back(colors[i]);
            dfs(p + 1);
            cur.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        read();
        dfs(0);
        cout << ways << '\n';
        for (const string& s : best) {
            cout << s << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
