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

constexpr int MAXN = 5003;
int n, m;
string essay[MAXN];
map<string, string> shortest;
map<string, int> lens;

string find(const string& s) {
    return shortest[s] = shortest[s] == s ? s : find(shortest[s]);
}

void merge(const string& a, const string& b) {
    string ar = find(a);
    string br = find(b);
    if (ar == br) return;
    shortest[ar] = br;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> essay[i];
        shortest[essay[i]] = essay[i];
    }

    string u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        if (shortest.find(u) == end(shortest))
            shortest[u] = u;
        if (shortest.find(v) == end(shortest))
            shortest[v] = v;

        merge(u, v);
    }

    for (auto it : shortest) {
        lens[it.first] = 1e9;
    }

    for (auto it : shortest) {
        lens[find(it.first)] = min(lens[find(it.first)], (int)it.first.size());
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += lens[find(essay[i])];
    }

    cout << ans << '\n';

    return 0;
}
