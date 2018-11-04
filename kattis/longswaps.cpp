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

const int MAXN = 102;

namespace uf {
    int uf[MAXN];

    void init(const int& n) {
        for (int i = 0; i <= n; ++i)
            uf[i] = i;
    }

    int find(int x) {
        return uf[x] = uf[x] == x ? x : find(uf[x]);
    }

    int merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return false;

        uf[xr] = yr;
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    uf::init(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i + k; j < n; ++j)
            uf::merge(i, j);
    }

    string t(s);
    vector<bool> vis(n, false);

    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        vector<int> inds;
        vector<char> chars;
        for (int j = i; j < n; ++j) {
            if (uf::find(i) == uf::find(j)) {
                vis[j] = true;
                inds.push_back(j);
                chars.push_back(s[j]);
            }
        }

        sort(begin(chars), end(chars));
        for (int j = 0; j < inds.size(); ++j) {
            t[inds[j]] = chars[j];
        }
    }

    string t2(s);
    sort(begin(t2), end(t2));

    if (t == t2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
