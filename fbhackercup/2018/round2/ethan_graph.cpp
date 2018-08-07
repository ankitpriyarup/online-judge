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

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 2) {
        cout << "0\n1\n1 2 1\n";
        return;
    }

    int fin = n;
    if (n > k) {
        n = k;
    }

    vector<pii> edges;
    int cost = k - 1;
    int diff = -k;
    for (int i = 1; i + 1 <= n; ++i) {
        edges.emplace_back(i, cost);
        diff += cost;
        --cost;
    }

    if (cost < 0 or diff < 0) {
        cout << "0\n1\n1 " << fin << " 1\n";
        return;
    }

    cout << diff << '\n';
    cout << n << '\n';
    cout << "1 " << fin << " " << k << '\n';
    for (auto& e : edges) {
        int dst = e.first + 1;
        if (dst == n) {
            dst = fin;
        }
        cout << e.first << " " << dst << " " << e.second << '\n';
    }
}

/*
 *
 * 5 5
 * 1 5 5
 *
 * 1 2 4
 * 2 3 3
 * 3 4 2
 * 4 5 1
 *
 * 10 -5 = 5 
 *
 * 1 42 48
 * 1 2 47
 * 2 3 46
 * ...
 * 41 42 7
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}
