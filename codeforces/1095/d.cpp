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

    int n;
    cin >> n;
    vector<vector<int>> neighbors(n + 1);
    vector<pii> edges(n + 1);
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
        edges[i] = {a, b};
    }

    // 1 4 2 3 5
    vector<int> ans = {1, neighbors[1][0]};
    for (int i = 1; i <= n - 2; ++i) {
        int a, b;
        a = neighbors[ans.back()][0];
        b = neighbors[ans.back()][1];
        if (ans[(int)ans.size() - 2] == a) {
            ans.push_back(b);
        } else {
            ans.push_back(a);
        }
    }

    int a = ans[1];
    int b = ans[2];
    if (edges[1] != pii{a, b} and edges[1] != pii{b, a})
        reverse(begin(ans), end(ans));

    for (int x : ans) 
        cout << x << ' ';
    
    return 0;
}
