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

constexpr int MAXN = 10004;
int n;
string name[MAXN];
string roots[5];
int house_size[MAXN];
string parent_name[MAXN];

int sz[MAXN];
vector<int> tree[MAXN];

int get(const vector<string>& v, const string& s) {
    return lower_bound(begin(v), end(v), s) - begin(v);
}

void dfs(int u, int par) {
    for (int v : tree[u]) {
        if (v == par) {
            continue;
        }

        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<string> all_names;
    for (int i = 0; i < 5; ++i) {
        cin >> roots[i];
        all_names.push_back(roots[i]);
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name[i] >> house_size[i] >> parent_name[i];
        all_names.push_back(name[i]);
        all_names.push_back(parent_name[i]);
    }

    sort(begin(all_names), end(all_names));
    all_names.erase(unique(begin(all_names), end(all_names)), end(all_names));

    for (int i = 0; i < n; ++i) {
        int idx = get(all_names, name[i]);
        int par = get(all_names, parent_name[i]);
        sz[idx] += house_size[i];
        tree[par].push_back(idx);
    }

    string best_name = "";
    int best_size = -1;
    for (int i = 0; i < 5; ++i) {
        int idx = get(all_names, roots[i]);
        dfs(idx, -1);
        if (sz[idx] > best_size) {
            best_size = sz[idx];
            best_name = roots[i];
        }
    }

    cout << best_name << '\n';

    return 0;
}
